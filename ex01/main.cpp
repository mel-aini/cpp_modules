#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data obj;
	obj.member = 10;
	uintptr_t raw = Serializer::serialize(&obj);
	Data *des = Serializer::deserialize(raw);

	std::cout << &obj << std::endl;
	std::cout << des << std::endl;
	std::cout << obj.member << std::endl;
}