#include "Array.hpp"
#include <iostream>


int main()
{
	try
	{
		Array<int> arr(4);
		arr[0] = 5;
		arr[1] = 10;
		arr[2] = 15;
		arr[3] = 20;

		Array<int> arr2 = arr;

		arr2[0] = -5;
		arr2[1] = -10;
		arr2[2] = -15;
		arr2[3] = -20;

		Array<std::string> arr3(2);
		arr3[0] = "hello";
		arr3[1] = "world";
		
		std::cout << "-> arr elements:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << std::endl;
		}
		std::cout << "-> arr2 elements:" << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++) {
			std::cout << arr2[i] << std::endl;
		}
		std::cout << "-> arr3 elements:" << std::endl;
		for (unsigned int i = 0; i < arr3.size(); i++) {
			std::cout << arr3[i] << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}