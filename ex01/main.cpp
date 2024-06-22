#include "iter.hpp"
#include <iostream>

template <typename T>
void f(T &a)
{
	a++;
}

template <typename T>
void print(T &a)
{
	std::cout << a << std::endl;
}

int main()
{
	{
		int arr[5] = {1, 2, 4, 5, 0};
		iter(arr, 5, f<int>);
		iter(arr, 5, print<int>);
	}
	{
		char arr[5] = {'c', 'b', 'd', 'e', 'f'};
		iter(arr, 5, f<char>);
		iter(arr, 5, print<char>);
	}
	{
		std::string arr[5] = {"hello", "world"};
		iter(arr, 2, print<std::string>);
	}
	return 0;
}