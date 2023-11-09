#include "PmergeMe.hpp"

// OCF
PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
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
	for (int i = 1; i < ac; i++)
	{
		int num = _intConvert(av[i]);

		_vec.push_back(num);
		_deq.push_back(num);
	}
}

void PmergeMe::print(const std::string &msg)
{
	std::cout << msg;
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _deq[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::sort(void)
{
	gettimeofday(&_vec_start, NULL);
	_mergeInsertSort(_vec, 0, _vec.size() - 1);
	gettimeofday(&_vec_finish, NULL);
	gettimeofday(&_deq_start, NULL);
	_mergeInsertSort(_deq, 0, _deq.size() - 1);
	gettimeofday(&_deq_finish, NULL);
}