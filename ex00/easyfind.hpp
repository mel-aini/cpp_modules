#pragma once
#include <iterator>
#include <algorithm>
#include <exception>

template <typename T>
int easyfind(T container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw "No occurrence is found";
	return *it;
}
