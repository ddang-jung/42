#include "Exception.hpp"

// OCF
Exception::Exception(void) {}
Exception::Exception(const Exception &ref) { (void)ref; }
Exception& Exception::operator=(Exception const &ref) {
	if (this != &ref) {
		this->~Exception();
		new (this) Exception(ref);
	}
	return (*this);
}
Exception::~Exception(void) {}

Exception::BadInputException::BadInputException(const std::string &msg)
	: std::invalid_argument("Error: bad input => " + msg) {}

const char	*Exception::BadInputException::what() const throw() {
	return (std::invalid_argument::what());
}

Exception::OpenFailException::OpenFailException(void)
	: std::runtime_error("Error: could not open file.") {}

const char	*Exception::OpenFailException::what() const throw() {
	return (std::runtime_error::what());
}