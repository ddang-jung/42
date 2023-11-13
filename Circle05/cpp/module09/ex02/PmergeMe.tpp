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
			_mergeInsertSort(src, start, mid);
			_mergeInsertSort(src, mid + 1, end);
			_mergeSort(src, start, mid, end);
		}
	}
}

template <typename T>
void PmergeMe::_mergeSort(T &src, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	std::vector<int> tmp(end - start + 1);

	while (i <= mid && j <= end)
	{
		if (src[i] < src[j])
			tmp[k++] = src[i++];
		else
			tmp[k++] = src[j++];
	}
	while (i <= mid)
		tmp[k++] = src[i++];
	while (j <= end)
		tmp[k++] = src[j++];
	for (int i = start; i <= end; i++)
		src[i] = tmp[i - start];
}

template <typename T>
void PmergeMe::_insertSort(T &src, int start, int end)
{
	for (int i = start + 1; i <= end; i++)
	{
		int tmp = src[i];
		int j = i - 1;
		while (j >= start && src[j] > tmp)
		{
			src[j + 1] = src[j];
			j--;
		}
		src[j + 1] = tmp;
	}
}