#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	iter(T *add, int len, void (*f)(T &elem))
{
	for(int i = 0; i < len; i++)
	{
		(*f)(add[i]);
	}
}
#endif
