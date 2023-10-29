#include "BitcoinExchange.hpp"

// OCF
BitcoinExchange::BitcoinExchange(void)
{
	_initData();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { *this = ref; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &ref)
{
	if (this != &ref)
	{
		this->_data = ref._data;
	}
	return (*this);
}
BitcoinExchange::~BitcoinExchange(void) {}

bool BitcoinExchange::_parseDate(const std::string &raw_date)
{
	if (raw_date == "")
		return (false);
	if (raw_date.length() != 10)
		return (false);
	if (raw_date[4] != '-' || raw_date[7] != '-')
		return (false);

	std::string raw_year = raw_date.substr(0, 4);
	std::string raw_mon = raw_date.substr(5, 2);
	std::string raw_day = raw_date.substr(8, 2);

	for (size_t i = 0; i < raw_year.length(); i++)
		if (!std::isdigit(raw_year[i]))
			return (false);
	for (size_t i = 0; i < raw_mon.length(); i++)
		if (!std::isdigit(raw_mon[i]))
			return (false);
	for (size_t i = 0; i < raw_day.length(); i++)
		if (!std::isdigit(raw_day[i]))
			return (false);

	int year = 0, mon = 0, day = 0;

	year = std::atoi(raw_year.c_str());
	mon = std::atoi(raw_mon.c_str());
	day = std::atoi(raw_day.c_str());

	if (year < 2009 || year > 2023)
		return (false);
	if (mon < 1 || mon > 12)
		return (false);
	if (day < 1)
		return (false);
	static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (mon == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		if (day > 29)
			return (false);
	if (day > days[mon])
		return (false);
	return (true);
}

bool BitcoinExchange::_parseRate(float *rate, const std::string &raw_rate)
{
	if (raw_rate == "")
		return (false);
	int i = 0;

	if (raw_rate[i] == '-')
		throw Exception::NegativeNumberException();
	if (raw_rate[i] == '+')
		i++;
	if (!std::isdigit(raw_rate[i]))
		return (false);
	while (std::isdigit(raw_rate[i]))
		i++;
	if (raw_rate[i] != '\0')
	{
		if (raw_rate[i] == '.')
			i++;
		else
			return (false);
		while (std::isdigit(raw_rate[i]))
			i++;
		if (raw_rate[i] != '\0')
			return (false);
	}
	*rate = std::atof(raw_rate.c_str());
	return (true);
}

void BitcoinExchange::_parseLine(const std::string &line)
{
	std::string raw_date, raw_rate;
	float rate = 0;

	if (line.find(',') == std::string::npos)
		throw Exception::BadInputException(line);

	raw_date = line.substr(0, line.find(','));
	raw_rate = line.substr(line.find(',') + 1);
	if (_parseDate(raw_date) == false || _parseRate(&rate, raw_rate) == false)
		throw Exception::BadInputException(line);
	_data.insert(std::pair<std::string, float>(raw_date, rate));
}

#include <iostream> // TEST HEADER
void BitcoinExchange::_initData(void)
{
	std::ifstream file("./data.csv");
	std::string line;

	if (!file.is_open())
		throw Exception::OpenFailException();
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw Exception::BadInputException(line);

	while (std::getline(file, line))
		_parseLine(line);

	// TEST PRINT
	// for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
	// 	std::cout << "Date: " << it->first << " | Rate: " << it->second << std::endl;
}

bool BitcoinExchange::_parseValue(float *val, const std::string &raw_val)
{
	if (_parseRate(val, raw_val) == false)
		return (false);
	if (*val > 1000.0f)
		throw Exception::TooLargeNumberException();
	return (true);
}

std::string BitcoinExchange::_formDate(int year, int mon, int day)
{
	std::ostringstream new_date;

	if (year < 2009)
		throw Exception::NoMatchingDateException();
	new_date << year;
	new_date << '-';
	if (mon < 10)
		new_date << '0';
	new_date << mon;
	new_date << '-';
	if (day < 10)
		new_date << '0';
	new_date << day;
	return (new_date.str());
}

void BitcoinExchange::_makeApproxDate(std::string &date)
{
	std::string raw_year = date.substr(0, 4);
	std::string raw_mon = date.substr(5, 2);
	std::string raw_day = date.substr(8, 2);
	int year = std::atoi(raw_year.c_str());
	int mon = std::atoi(raw_mon.c_str());
	int day = std::atoi(raw_day.c_str());
	static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day > 1)
		day--;
	else
	{
		if (mon > 1)
		{
			mon--;
			day = days[mon];
		}
		else
		{
			year--;
			mon = 12;
			day = days[mon];
		}
	}
	date = _formDate(year, mon, day);
}

void BitcoinExchange::_calculate(const std::string &line)
{
	std::string date, tmp;
	float val = 0;

	if (line.find('|') == std::string::npos)
		throw Exception::BadInputException(line);
	date = line.substr(0, line.find('|') - 1);
	if (_parseDate(date) == false || _parseValue(&val, line.substr(line.find('|') + 2)) == false)
		throw Exception::BadInputException(line);
	tmp = date;
	while (_data.find(date) == _data.end())
		_makeApproxDate(date);
	std::cout << tmp << " => " << val << " = " << _data.find(date)->second * val << std::endl;
}

void BitcoinExchange::_exchange(const std::string &filename)
{
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open())
		throw Exception::OpenFailException();
	std::getline(file, line);
	if (line != "date | value")
		throw Exception::BadInputException(line);

	while (std::getline(file, line))
	{
		try
		{
			_calculate(line);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}