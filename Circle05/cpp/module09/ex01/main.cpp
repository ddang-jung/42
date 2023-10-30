#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw(std::invalid_argument("Error"));

		RPN rpn;

		rpn.parse(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}