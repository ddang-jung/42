#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void) : std::stack<T>() {}
	MutantStack(const MutantStack &src) : std::stack<T>(src) {}
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
		{
			this->~MutantStack();
			new (this) MutantStack(rhs);
		}
		return (*this);
	}
	virtual ~MutantStack(void) {}

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin(void)
	{
		return (this->c.begin());
	}
	iterator end(void)
	{
		return (this->c.end());
	}
};