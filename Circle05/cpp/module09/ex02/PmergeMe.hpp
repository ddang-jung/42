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
	struct timeval _vec_start, _vec_finish;
	struct timeval _deq_start, _deq_finish;

private:
	void _throwError(void);
	int _intConvert(const std::string &str);

	template <typename T>
	void _mergeInsertSort(T &src, int start, int end);

public:
	// OCF
	PmergeMe(void);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	virtual ~PmergeMe(void);

	// MBF
	void parse(int ac, char **av);
	void print(const std::string &msg);
	void sort(void);
};

#endif