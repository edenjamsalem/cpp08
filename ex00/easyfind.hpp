#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iterator>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Element not found!");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator element;
	
	element = std::find(container.begin(), container.end(), n);	
	if (element == container.end())
		throw (NotFoundException());
	return (element);
}

#endif
