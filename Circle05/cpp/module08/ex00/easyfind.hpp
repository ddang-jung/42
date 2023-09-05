#pragma once

#include <exception>
#include <algorithm>

class noOccurrenceException : public std::exception
{
	const char *what() const throw()
	{
		return ("No occurrence.");
	}
};

template <typename T>
typename T::iterator easyfind(T &con, int num) // 컴파일러가 T가 typename인지 variablename인지 모르니 앞에 typename임을 명시해줘야 한다.
{
	typename T::iterator it;

	it = std::find(con.begin(), con.end(), num);
	if (it == con.end())
		throw noOccurrenceException();
	return (it);
}