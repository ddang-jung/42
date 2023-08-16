#include "ScalarConverter.hpp"

// OCF
ScalarConverter::ScalarConverter(void) {
}
ScalarConverter::ScalarConverter(const ScalarConverter &ref) {
	(void)ref;
}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &ref) {
	(void)ref;
	return (*this);
}
ScalarConverter::~ScalarConverter(void) {
}

// INIT
int		ScalarConverter::checkType(t_info *info, const std::string &str) {
	int	ipart_len = 0;
	int	rpart_len = 0;

	if (info->len == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return (CHAR);
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		return (FLOAT);
	else if (str == "-inf" || str == "+inf" || str == "nan")
		return (DOUBLE);
	else {
		size_t	i = 0;

		if (str[i] == '-' || str[i] == '+')
			i++;
		while (std::isdigit(str[i])) {
			ipart_len++;
			i++;
		}
		if (ipart_len == 0)
			return (NONE);
		else if (i == info->len)
			return (INT);
		else if (str[i] == '.') {
			while (std::isdigit(str[++i]))
				rpart_len++;
			if (rpart_len == 0)
				return (NONE);
			else if (i == info->len)
				return (DOUBLE);
			else if (str[i] == 'f' && i + 1 == info->len)
				return (FLOAT);
			else
				return (NONE);
		}
		else
			return (NONE);
	}
}
void	ScalarConverter::initInfo(t_info *info, const std::string &str) {
	info->cstr = str.c_str();
	info->len = str.length();
	info->type = checkType(info, str);
	info->cast.cvalue = 0;
	info->cast.ivalue = 0;
	info->cast.fvalue = 0;
	info->cast.dvalue = 0;
	info->cast.result[CHAR] = FAIL;
	info->cast.result[INT] = FAIL;
	info->cast.result[FLOAT] = FAIL;
	info->cast.result[DOUBLE] = FAIL;
}

// TYPE CONVERT
void	ScalarConverter::convertFromChar(t_info *info) {
	info->cast.cvalue = info->cstr[0];
	info->cast.ivalue = static_cast<int>(info->cast.cvalue);
	info->cast.fvalue = static_cast<float>(info->cast.cvalue);
	info->cast.dvalue = static_cast<double>(info->cast.cvalue);
	info->cast.result[CHAR] = SUCCESS;
	info->cast.result[INT] = SUCCESS;
	info->cast.result[FLOAT] = SUCCESS;
	info->cast.result[DOUBLE] = SUCCESS;
}
void	ScalarConverter::convertFromInt(t_info *info) {
	long	ltemp = std::strtol(info->cstr, NULL, 10);

	if (errno != ERANGE && ltemp == static_cast<int>(ltemp)) {
		info->cast.ivalue = static_cast<int>(ltemp);
		info->cast.result[INT] = SUCCESS;
		if (std::isprint(info->cast.ivalue)) {
			info->cast.cvalue = static_cast<char>(info->cast.ivalue);
			info->cast.result[CHAR] = SUCCESS;
		}
	}

	float	ftemp = std::strtof(info->cstr, NULL);;

	if (errno != ERANGE) {
		info->cast.fvalue = ftemp;
		info->cast.result[FLOAT] = SUCCESS;
	}

	double	dtemp = std::strtod(info->cstr, NULL);

	if (errno != ERANGE) {
		info->cast.dvalue = dtemp;
		info->cast.result[DOUBLE] = SUCCESS;
	}
}
void	ScalarConverter::convertFromFloat(t_info *info) {
	float	ftemp = std::strtof(info->cstr, NULL);

	if (errno != ERANGE) {
		info->cast.fvalue = ftemp;
		info->cast.result[FLOAT] = SUCCESS;
		if (info->cast.fvalue - static_cast<int>(info->cast.fvalue) == 0.0f) {
			info->cast.ivalue = static_cast<int>(info->cast.fvalue);
			info->cast.result[INT] = SUCCESS;
			if (std::isprint(info->cast.ivalue)) {
				info->cast.cvalue = static_cast<char>(info->cast.ivalue);
				info->cast.result[CHAR] = SUCCESS;
			}
		}
	}

	double	dtemp = std::strtod(info->cstr, NULL);

	if (errno != ERANGE) {
		info->cast.dvalue = dtemp;
		info->cast.result[DOUBLE] = SUCCESS;
	}
}
void	ScalarConverter::convertFromDouble(t_info *info) {
	double	dtemp = std::strtod(info->cstr, NULL);

	if (errno != ERANGE) {
		info->cast.dvalue = dtemp;
		info->cast.result[DOUBLE] = SUCCESS;
		if (info->cast.dvalue - static_cast<int>(info->cast.dvalue) == 0.0) {
			info->cast.ivalue = static_cast<int>(info->cast.dvalue);
			info->cast.result[INT] = SUCCESS;
			if (std::isprint(info->cast.ivalue)) {
				info->cast.cvalue = static_cast<char>(info->cast.ivalue);
				info->cast.result[CHAR] = SUCCESS;
			}
		}
		info->cast.fvalue = std::strtof(info->cstr, NULL);
		info->cast.result[FLOAT] = SUCCESS;
	}
}

// PRINT
bool	ScalarConverter::isPseudo(const std::string &str) {
	if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf")
		return (true);
	else
		return (false);
}
void	ScalarConverter::printPseudo(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl; 
	}
}
void	ScalarConverter::printChar(t_info *info) {
	std::cout << "char: ";
	if (info->cast.result[CHAR] == SUCCESS)
		std::cout << info->cast.cvalue << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}
void	ScalarConverter::printInt(t_info *info) {
	std::cout << "int: ";
	if (info->cast.result[INT] == SUCCESS)
		std::cout << info->cast.ivalue << std::endl;
	else
		std::cout << "impossible" << std::endl;
}
void	ScalarConverter::printFloat(t_info *info) {
	std::cout << "float: ";
	if (info->cast.result[FLOAT] == SUCCESS) {
		if (info->cast.fvalue - std::floor(info->cast.fvalue) == 0.0f)
			std::cout << info->cast.fvalue << ".0f" << std::endl;
		else
			std::cout << info->cast.fvalue << 'f' << std::endl;
	}
	else
		std::cout << "nanf" << std::endl;
}
void	ScalarConverter::printDouble(t_info *info) {
	std::cout << "double: ";
	if (info->cast.result[DOUBLE] == SUCCESS) {
		if (info->cast.dvalue - std::floor(info->cast.dvalue) == 0.0)
			std::cout << info->cast.dvalue << ".0" << std::endl;
		else
			std::cout << info->cast.dvalue << std::endl;
	}
	else
		std::cout << "nan" << std::endl;
}
void	ScalarConverter::print(t_info *info, const std::string &str) {
	if (isPseudo(str)) {
		printPseudo(str);
		return ;
	}
	printChar(info);
	printInt(info);
	printFloat(info);
	printDouble(info);
}

void	ScalarConverter::convert(const std::string &str) {
	t_info	info;

	initInfo(&info, str);
	switch (info.type) {
		case CHAR :
			convertFromChar(&info);
			break ;
		case INT :
			convertFromInt(&info);
			break ;
		case FLOAT :
			convertFromFloat(&info);
			break ;
		case DOUBLE :
			convertFromDouble(&info);
			break ;
	}
	print(&info, str);
}