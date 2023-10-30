#ifndef PmergeMe_HPP
#define PmergeMe_HPP

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	virtual ~PmergeMe(void);

private:
};

#endif