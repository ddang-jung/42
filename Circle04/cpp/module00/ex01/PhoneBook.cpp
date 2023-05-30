#include "PhoneBook.hpp"

// TODO
void	PhoneBook::print_info(int idx) {
	std::cout << "## First name : ";
	std::cout << arr[idx].get_firstname() << std::endl;
	std::cout << "## Last name : ";
	std::cout << arr[idx].get_lastname() << std::endl;
	std::cout << "## Nickname : ";
	std::cout << arr[idx].get_nickname() << std::endl;
	std::cout << "## Phone number : ";
	std::cout << arr[idx].get_phonenumber() << std::endl;
	std::cout << "## Darkest secret : ";
	std::cout << arr[idx].get_darkestsecret() << std::endl;
}

void	PhoneBook::add(void) {
	if (idx == 8)
		idx = 0;
	std::cout << "## ADD MODE" << std::endl;
	std::cout << ">> First name : ";
	arr[idx].set_firstname();
	std::cout << ">> Last name : ";
	arr[idx].set_lastname();
	std::cout << ">> Nickname : ";
	arr[idx].set_nickname();
	std::cout << ">> Phone number : ";
	arr[idx].set_phonenumber();
	std::cout << ">> Darkest secret : ";
	arr[idx].set_darkestsecret();
	std::cout << "## END ADD MODE" << std::endl;
	idx++;
}

std::string	parsor(std::string str) {
	std::string	ret;

	if (str.length() > 10) {
		ret = str.substr(0, 9);
		return (ret + '.');
	}
	else
		return (str);
}

void	print_category(void) {
	std::cout << std::setw(10) << "INDEX" << '|';
	std::cout << std::setw(10) << "FIRST NAME" << '|';
	std::cout << std::setw(10) << "LAST NAME" << '|';
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
}

void	print_guide(void) {
	std::cout << "#1 More information? => type index number";
	std::cout << std::endl;
	std::cout << "#2 End search mode?  => type anything else";
	std::cout << std::endl;
	std::cout << ">> ";
}

void	PhoneBook::search(void) {
	int			idx;
	std::string	input;

	std::cout << "## SEARCH MODE" << std::endl;
	print_category();
	for (int i = 0; i < 8; ++i) {
		std::cout << std::setw(10) << i << '|';
		std::cout << std::setw(10) << parsor(arr[i].get_firstname()) << '|';
		std::cout << std::setw(10) << parsor(arr[i].get_lastname()) << '|';
		std::cout << std::setw(10) << parsor(arr[i].get_nickname());
		std::cout << std::endl;
	}
	print_guide();
	std::getline(std::cin, input);
	idx = std::atoi(input.c_str());
	if (idx >= 0 && idx <= 7)
		print_info(idx);
	std::cout << "## END SEARCH MODE";
	std::cout << std::endl;
}

void	PhoneBook::wrong(void) {
	std::cout << "## Wrong argument";
	std::cout << std::endl;
	std::cout << "## Choose one of the options below";
	std::cout << std::endl;
	std::cout << "## ( ADD | SEARCH | EXIT )";
	std::cout << std::endl;
}

PhoneBook::PhoneBook(void)
	: idx(0) {}

PhoneBook::~PhoneBook(void) {}