#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ElementNotFound : public std::exception
{
	public :
		char const *what() const throw()
		{
			return("Element not found exception");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator it;

	 it = std::find(container.begin(), container.end(), to_find);
	 if(it == container.end())
		 throw ElementNotFound();
	 return (it);
}

#endif
