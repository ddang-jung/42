#pragma once

template <typename T>
void PmergeMe::_mergeInsertSort(T &src, int start, int end)
{
	if (start < end)
	{
		if (end - start < 70)
			_insertSort(src, start, end);
		else
		{
			int mid = (start + end) / 2;
			_mergeInsertSort(T & src, start, mid);
			_mergeInsertSort(T & src, mid + 1, end);
			_mergeSort(src, start, mid, end);
		}
	}
}