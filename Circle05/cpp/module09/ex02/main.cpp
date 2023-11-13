#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		PmergeMe pm;

		pm.parse(ac, av);
		pm.printElements("Before:  ");
		pm.sort();
		pm.printElements("After:   ");
		pm.printTime();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}