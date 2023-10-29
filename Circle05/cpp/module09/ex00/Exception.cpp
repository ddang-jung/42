#include "Exception.hpp"

// OCF
Exception::Exception(void) {}
Exception::Exception(const Exception &ref) { (void)ref; }
Exception &Exception::operator=(Exception const &ref)
{
	if (this != &ref)
	{
		this->~Exception();
		new (this) Exception(ref);
	}
	return (*this);
}
Exception::~Exception(void) {}

Exception::OpenFailException::OpenFailException(void)
	: std::runtime_error("Error: could not open file.") {}

const char *Exception::OpenFailException::what() const throw()
{
	return (std::runtime_error::what());
}

Exception::NoMatchingDateException::NoMatchingDateException(void)
	: std::runtime_error("Error: no matching date.") {}

const char *Exception::NoMatchingDateException::what() const throw()
{
	return (std::runtime_error::what());
}

Exception::BadInputException::BadInputException(const std::string &msg)
	: std::invalid_argument("Error: bad input => " + msg) {}

const char *Exception::BadInputException::what() const throw()
{
	return (std::invalid_argument::what());
}

Exception::NegativeNumberException::NegativeNumberException(void)
	: std::invalid_argument("Error: not a positive number.") {}

const char *Exception::NegativeNumberException::what() const throw()
{
	return (std::invalid_argument::what());
}

Exception::TooLargeNumberException::TooLargeNumberException(void)
	: std::invalid_argument("Error: too large a number.") {}

const char *Exception::TooLargeNumberException::what() const throw()
{
	return (std::invalid_argument::what());
}
