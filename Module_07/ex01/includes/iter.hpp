#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cctype>
#include <string>

template <typename T> void iter (T *tab, size_t len, void (*fun)(T &))
{
	if (tab == NULL || fun == NULL)
		return;
	for (size_t i = 0 ; i < len ; i++)
		fun(tab[i]);
}

#endif