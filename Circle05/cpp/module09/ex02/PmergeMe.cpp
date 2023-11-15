#include "PmergeMe.hpp"

// OCF
PmergeMe::PmergeMe(void) : vec_time(0.0), deq_time(0.0) {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
		this->vec_time = rhs.vec_time;
		this->deq_time = rhs.deq_time;
	}
	return *this;
}
PmergeMe::~PmergeMe(void) {}

// MBF
void PmergeMe::_throwError(void)
{
	throw std::runtime_error("Error");
}

int PmergeMe::_intConvert(const std::string &str)
{
	size_t i = 0;

	if (str[i] == '-')
		_throwError();
	if (str[i] == '+')
		i++;
	for (; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			_throwError();

	int result = std::atoi(str.c_str());

	if (str.length() == 1 && str[0] == '0')
		return (0);
	else if (result == 0)
		_throwError();
	return (result);
}

void PmergeMe::parse(int ac, char **av)
{
	if (ac < 2)
		_throwError();
	for (int i = 1; i < ac; i++)
	{
		int num = _intConvert(av[i]);

		_vec.push_back(num);
		_deq.push_back(num);
	}
}

void PmergeMe::printElements(const std::string &msg)
{
	std::cout << msg;
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (_vec[i] != _deq[i])
			_throwError();
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

std::time_t PmergeMe::_getCurrentTime(void)
{
	struct timeval curr;

	gettimeofday(&curr, NULL);
	return (curr.tv_sec * 1000000UL + curr.tv_usec);
}

void PmergeMe::sort(void)
{
	std::time_t start, finish;

	start = _getCurrentTime();
	_mergeInsertionSort(_vec);
	finish = _getCurrentTime();
	vec_time = static_cast<double>(finish - start);
	start = _getCurrentTime();
	_mergeInsertionSort(_deq);
	finish = _getCurrentTime();
	deq_time = static_cast<double>(finish - start);
}

void PmergeMe::printTime(void)
{
	std::cout << "Time to process a range of " << _vec.size();
	std::cout << " elements with std::vector : " << vec_time << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size();
	std::cout << " elements with std::deque : " << deq_time << " us" << std::endl;
}