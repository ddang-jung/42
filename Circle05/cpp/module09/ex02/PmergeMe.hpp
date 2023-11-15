#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

private:
	void _throwError(void);
	int _intConvert(const std::string &str);
	std::time_t _getCurrentTime(void);

	template <typename T>
	void _mergeInsertionSort(T &src) const;

public:
	double vec_time, deq_time;

	// OCF
	PmergeMe(void);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	virtual ~PmergeMe(void);

	// MBF
	void parse(int ac, char **av);
	void printElements(const std::string &msg);
	void sort(void);
	void printTime(void);
};

#include "PmergeMe.tpp"

#endif