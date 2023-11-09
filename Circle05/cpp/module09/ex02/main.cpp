#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		PmergeMe pm;

		pm.parse(ac, av);
		pm.print("Before:  ");
		pm.sort();
		pm.print("After:   ");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}