#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	try
	{
		std::cout << *easyfind(vec, 10) << std::endl;
		std::cout << *easyfind(vec, 20) << std::endl;
		std::cout << *easyfind(vec, 30) << std::endl;
		std::cout << *easyfind(vec, 42) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}