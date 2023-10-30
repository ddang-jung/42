#include "RPN.hpp"

// OCF
RPN::RPN(void) {}
RPN::RPN(const RPN &src) { *this = src; }
RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		this->_data = rhs._data;
	return *this;
}
RPN::~RPN(void) {}

// MBF
void RPN::_throwError(void)
{
	throw std::runtime_error("Error");
}

bool RPN::_isOperator(char c)
{
	std::string operators = "+-/*";

	if (operators.find(c) == std::string::npos)
		return (false);
	return (true);
}

void RPN::_calculate(char oprt)
{
	if (_data.size() < 2)
		_throwError();

	int a = _data.top();
	_data.pop();
	int b = _data.top();
	_data.pop();
	int rst;

	if (oprt == '+')
		rst = b + a;
	else if (oprt == '-')
		rst = b - a;
	else if (oprt == '/')
		rst = b / a;
	else if (oprt == '*')
		rst = b * a;
	_data.push(rst);
}

void RPN::parse(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]))
			continue;
		else if (std::isdigit(str[i]))
			_data.push(str[i] - '0');
		else if (_isOperator(str[i]))
			_calculate(str[i]);
		else
			_throwError();
	}
	if (_data.size() != 1)
		_throwError();
	else
		std::cout << _data.top() << std::endl;
}