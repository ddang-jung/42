#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
}
Span::Span(const Span &src) : _N(src._N)
{
	this->_vec = src._vec;
}
Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->~Span();
		new (this) Span(rhs);
	}
	return *this;
}
Span::~Span(void)
{
}

void Span::addNumber(int num)
{
	if (_vec.size() == _N)
		throw noEmptySpaceException();
	_vec.push_back(num);
}
unsigned int Span::shortestSpan(void)
{
	if (_vec.size() <= 1)
		throw nothingToCompareException();
	std::sort(_vec.begin(), _vec.end());
	unsigned int min = *_vec.rbegin() - *_vec.begin();
	for (std::vector<int>::iterator it = _vec.begin(); it + 1 != _vec.end(); it++)
		if (min > (unsigned int)(*(it + 1) - *it))
			min = (unsigned int)(*(it + 1) - *it);
	return (min);
}
unsigned int Span::longestSpan(void)
{
	if (_vec.size() <= 1)
		throw nothingToCompareException();
	std::sort(_vec.begin(), _vec.end());
	return (*_vec.rbegin() - *_vec.begin());
}
void Span::addManyNumbers(void)
{
	if (_vec.size() == _N)
		throw noEmptySpaceException();
	std::srand(time(NULL));
	for (; _vec.size() < _N;)
	{
		_vec.push_back(std::rand() % _N);
	}
}
// void Span::printVector(void)
// {
// 	std::cout << "numbers: ";
// 	for (unsigned int i = 0; i < _N; i++)
// 		std::cout << _vec[i] << ',';
// 	std::cout << std::endl;
// }