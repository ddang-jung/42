#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(Span const &rhs);
	virtual ~Span(void);

	void addNumber(int num);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	void addManyNumbers(void);
	// void printVector(void);
	class noEmptySpaceException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Unable to add numbers more than N.");
		}
	};
	class nothingToCompareException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Nothing to compare.");
		}
	};

private:
	unsigned int _N;
	std::vector<int> _vec;
};