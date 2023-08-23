#ifndef Array_HPP
#define Array_HPP

#include <exception>

template <typename T>
class Array
{
private:
	T *_arr;
	const unsigned int _size;

public:
	Array(void) : _size(0)
	{
		_arr = new T[_size];
	}
	Array(unsigned int n) : _size(n)
	{
		_arr = new T[_size];
	}
	Array(const Array &src) : _size(src._size)
	{
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			this->_arr[i] = src._arr[i];
		}
	}
	Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			this->~Array();
			new (this) Array(rhs);
		}
		return (*this);
	}
	virtual ~Array(void)
	{
		if (this->_arr)
			delete[] _arr;
	}

	const unsigned int &size(void) const
	{
		return (_size);
	}
	T &operator[](const unsigned int index) const
	{
		if (index >= this->_size)
			throw indexOutOfBoundsException();
		return (_arr[index]);
	}
	class indexOutOfBoundsException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Index is out of bounds.");
		}
	};
};

#endif