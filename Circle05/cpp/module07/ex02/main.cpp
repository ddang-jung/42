#include "Array.hpp"
#include <iostream>

int main(void)
{
	{
		Array<int> iarr(5);
		std::cout << "iarr     : ";
		try
		{
			for (unsigned int i = 0;; i++)
			{
				iarr[i] = i;
				std::cout << iarr[i] << ", ";
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		Array<int> copy_iarr(iarr);
		std::cout << "copy_iarr: ";
		try
		{
			for (unsigned int i = 0;; i++)
				std::cout << iarr[i] << ", ";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Array<std::string> carr(1);
		std::cout << "carr     : ";
		try
		{
			carr[0] = "hi my type is string now!";
			std::cout << carr[0] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		Array<std::string> copy_carr;
		copy_carr = carr;
		std::cout << "copy_carr: ";
		try
		{
			std::cout << copy_carr[0] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}