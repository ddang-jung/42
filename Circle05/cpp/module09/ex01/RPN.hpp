#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<int> _data;

private:
	void _throwError();
	bool _isOperator(char c);
	void _calculate(char oprt);

public:
	// OCF
	RPN(void);
	RPN(const RPN &src);
	RPN &operator=(RPN const &rhs);
	virtual ~RPN(void);
	// MBF
	void parse(const std::string &str);
};

#endif