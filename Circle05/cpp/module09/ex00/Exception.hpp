#pragma once

#include <exception>
#include <string>

class Exception
{
private:
	// OCF
	Exception(void);
	Exception(const Exception &ref);
	Exception &operator=(Exception const &ref);
	virtual ~Exception(void);

public:
	class OpenFailException : public std::runtime_error
	{
	public:
		OpenFailException(void);
		virtual const char *what() const throw();
	};
	class NoMatchingDateException : public std::runtime_error
	{
	public:
		NoMatchingDateException(void);
		virtual const char *what() const throw();
	};
	class BadInputException : public std::invalid_argument
	{
	public:
		BadInputException(const std::string &msg);
		virtual const char *what() const throw();
	};
	class NegativeNumberException : public std::invalid_argument
	{
	public:
		NegativeNumberException(void);
		virtual const char *what() const throw();
	};
	class TooLargeNumberException : public std::invalid_argument
	{
	public:
		TooLargeNumberException(void);
		virtual const char *what() const throw();
	};
};