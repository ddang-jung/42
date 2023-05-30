#include "Contact.hpp"

std::string	get_input(void) {
	std::string	input;

	input.clear();
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "## Empty input is not allowed";
		std::cout << std::endl << ">> ";
		std::getline(std::cin, input);
	}
	return (input);
}

void	Contact::set_firstname(void) {
	firstname = get_input();
}

void	Contact::set_lastname(void) {
	lastname = get_input();
}

void	Contact::set_nickname(void) {
	nickname = get_input();
}

void	Contact::set_phonenumber(void) {
	phonenumber = get_input();
}

void	Contact::set_darkestsecret(void) {
	darkestsecret = get_input();
}

std::string	Contact::get_firstname(void) {
	return (firstname);
}

std::string	Contact::get_lastname(void) {
	return (lastname);
}

std::string	Contact::get_nickname(void) {
	return (nickname);
}

std::string	Contact::get_phonenumber(void) {
	return (phonenumber);
}

std::string	Contact::get_darkestsecret(void) {
	return (darkestsecret);
}

Contact::Contact(void)
	:	firstname("")
	,	lastname("")
	,	nickname("")
	,	phonenumber("")
	,	darkestsecret("") {}

Contact::~Contact(void) {}