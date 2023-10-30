#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw Exception::OpenFailException();
		BitcoinExchange exchange_center;

		exchange_center._exchange(av[1]);
		(void)ac;
		(void)av;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}