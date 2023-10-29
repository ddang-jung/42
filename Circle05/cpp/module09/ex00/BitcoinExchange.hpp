#pragma once

#include "Exception.hpp"
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;

private:
	void _initData(void);
	void _parseLine(const std::string &line);
	bool _parseDate(const std::string &raw_date);
	bool _parseRate(float *rate, const std::string &raw_rate);
	bool _parseValue(float *val, const std::string &raw_val);
	void _makeApproxDate(std::string &date);
	std::string _formDate(int year, int mon, int day);
	void _calculate(const std::string &line);

public:
	// OCF
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &ref);
	BitcoinExchange &operator=(BitcoinExchange const &ref);
	virtual ~BitcoinExchange(void);

	// MBF
	void _exchange(const std::string &filename);
};