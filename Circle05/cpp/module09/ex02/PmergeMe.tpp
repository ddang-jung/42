#pragma once

template <typename T>
void PmergeMe::_mergeInsertSort(T &src) const
{
	T mainChain;
	T pendingElements;
	bool	odd = false;
	int struggler = 0;

	if (src.size() == 1)
		return;

	/*
		search two at a time
		larger to MainChain
		smaller to PendingElements
		if odd, fill struggler
	*/
	for (size_t i = 0; i < src.size(); i += 2)
	{
		if ((i + 1) != src.size())
		{
			int large, small;

			large = src[i] > src[i + 1] ? src[i] : src[i + 1];
			small = src[i] < src[i + 1] ? src[i] : src[i + 1];
			mainChain.push_back(large);
			pendingElements.push_back(small);
		}
		else
		{
			odd = true;
			struggler = src[i];
		}
	}

	//	sort in ascending order
	for (size_t i = 0; i < mainChain.size() - 1; i++)
	{
		for (size_t j = 0; j < mainChain.size() - i - 1; j++)
		{
			if (mainChain[j] > mainChain[j + 1])
			{
				std::swap(mainChain[j], mainChain[j + 1]);
				std::swap(pendingElements[j], pendingElements[j + 1]);
			}
		}
	}

	/*
		make Jacobsthal Vector
		(1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365..)
	*/
	std::vector<size_t> jacobsthal;

	jacobsthal.push_back(1);
	for (size_t i = 0;;i++)
	{
		size_t next = (2 * jacobsthal[i]) + (i % 2 ? -1 : 1);
		jacobsthal.push_back(next);
		if (next >= pendingElements.size())
			break;
	}

	//	first element in pendingElements must be smaller than first element in mainChain
	mainChain.insert(mainChain.begin(), pendingElements[0]);
	
	//	insertion sort using Jacobsthal Number
	for (size_t i = 0; i < jacobsthal.size() - 1; i++)
	{
		size_t max = jacobsthal[i + 1] < pendingElements.size() ? jacobsthal[i + 1] : pendingElements.size();
		size_t min = jacobsthal[i];
		for (max -= 1; max >= min; max--)
		{
			int target = pendingElements[max];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), target), target);
		}
	}
	if (odd)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), struggler), struggler);

	src = mainChain;
}
