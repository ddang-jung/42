#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(const T &element)
{
	std::cout << element << std::endl;
}

int main(void)
{
	int iarr[SIZE] = {0, 1, 2, 3, 4};
	char carr[SIZE] = {'a', 'b', 'c', 'd', 'e'};
	std::string sarr[SIZE] = {"hi", "this", "is", "string", "array"};

	iter(iarr, SIZE, printElement);
	printElement("");
	iter(carr, SIZE, printElement);
	printElement("");
	iter(sarr, SIZE, printElement);

	return 0;
}