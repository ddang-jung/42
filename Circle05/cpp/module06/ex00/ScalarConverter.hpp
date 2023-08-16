#pragma once

# include <string>
# include <cctype>
# include <cmath>
# include <iostream>

typedef enum	e_result {
	SUCCESS,
	FAIL
}	t_result;

typedef enum	e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
}	t_type;

typedef struct	s_cast {
	char	cvalue;
	int		ivalue;
	float	fvalue;
	double	dvalue;
	bool	result[4];
}	t_cast;

typedef struct	s_info {
	const char	*cstr;
	size_t		len;
	int			type;
	t_cast		cast;
}	t_info;

class ScalarConverter
{
	private:
		// OCF
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& ref);
		ScalarConverter	&operator=(ScalarConverter const& ref);
		virtual	~ScalarConverter(void);

		// INIT
		static void	initInfo(t_info *info, const std::string &str);
		static int	checkType(t_info *info, const std::string &str);

		// TYPE CONVERT
		static void	convertFromChar(t_info *info);
		static void	convertFromInt(t_info *info);
		static void	convertFromFloat(t_info *info);
		static void	convertFromDouble(t_info *info);

		// PRINT
		static bool	isPseudo(const std::string &str);
		static void	printPseudo(const std::string &str);
		static void	printChar(t_info *info);
		static void	printInt(t_info *info);
		static void	printFloat(t_info *info);
		static void	printDouble(t_info *info);
		static void	print(t_info *info, const std::string &str);

	public:
		static void	convert(const std::string &str);
};