#include "iter.hpp"
#include <iostream>

template <typename T>
void	printWithAddOne(const T &element) {
	std::cout << element + 1 << std::endl;
}

int main( void ) {
	int	arr[5] = {0, 1, 2, 3, 4};

	iter(arr, 5, printWithAddOne);

	return 0;
}