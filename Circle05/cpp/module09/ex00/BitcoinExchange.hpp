#pragma once

#include "Exception.hpp"
#include <map>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;

	private:
		void		_initData(void);
		void		_parseLine(const std::string &line);
		bool		_parseDate(const std::string &raw_date);
		bool		_parseRate(float *rate, const std::string &raw_rate);
		void		_exchange(const std::string &filename);
		void		_calculate(const std::string &line);

	public:
		// OCF
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange	&operator=(BitcoinExchange const& ref);
		virtual	~BitcoinExchange(void);
};