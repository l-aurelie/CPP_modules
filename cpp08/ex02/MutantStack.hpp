#ifndef MUTANSTACK_HPP 
#define MUTANSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack &src) { *this = src; }
	~MutantStack() {}
	
	MutantStack &operator=(const MutantStack &rhs)
	{
		std::stack<T>::operator=(rhs);
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
};

#endif
