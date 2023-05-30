#include "PhoneBook.hpp"

void	welcome(void) {
	std::cout << "## Welcome to hyeonjun's Awesome PhoneBook";
	std::cout << std::endl;
}

void	goodbye(void) {
	std::cout << "## Bye Bye!!";
	std::cout << std::endl;
}

std::string	get_command(void) {
	std::string	cmd;

	std::cout << "## Type a Command";
	std::cout << std::endl;
	std::cout << ">> ";
	std::getline(std::cin, cmd);
	return (cmd);
}

int	main(void) {
	PhoneBook	book;
	std::string	cmd;

	welcome();
	while (true)
	{
		cmd = get_command();
		if (cmd == "ADD")
			book.add();
		else if (cmd == "SEARCH")
			book.search();
		else if (cmd == "EXIT")
			break ;
		else if (std::cin.eof()) {
			std::cout << std::endl;
			break ;
		}
		else
			book.wrong();
	}
	goodbye();
	return (0);
}
