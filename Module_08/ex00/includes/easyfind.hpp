#pragma once

#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &tab, int tofind)
{
	typename T::iterator it;
	for (it = tab.begin() ; it < tab.end() ; it++)
	{
		if (*it == tofind)
			return (it);
	}
	std::cout << "Easyfind: Not Found." << std::endl;
	return (tab.end());
}