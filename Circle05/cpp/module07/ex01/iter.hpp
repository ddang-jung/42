#pragma once

#include <cstdlib>

template <typename T>
void	iter(const T *arr, size_t len, void (*f)(const T &)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}