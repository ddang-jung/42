#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av) {
	Harl		harl;
	int			num;

	if (ac != 2)
		std::cout << "Error: Unvalid Arguments." << std::endl;
	else {
		num = harl.checkLevel(std::string(av[1]));
		switch (num) {
			case -1 :
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break ;
			case 0 :
				std::cout << "[ DEBUG ]" << std::endl;
				harl.complain("DEBUG");
				std::cout << std::endl;
			case 1 :
				std::cout << "[ INFO ]" << std::endl;
				harl.complain("INFO");
				std::cout << std::endl;
			case 2 :
				std::cout << "[ WARNING ]" << std::endl;
				harl.complain("WARNING");
				std::cout << std::endl;
			case 3 :
				std::cout << "[ ERROR ]" << std::endl;
				harl.complain("ERROR");
				std::cout << std::endl;
		}
	}
	return (0);
}
