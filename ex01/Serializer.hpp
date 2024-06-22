#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
        Serializer();

    public:
        Serializer(const Serializer& S);
        Serializer& operator= (const Serializer& C);
        ~Serializer();

		static uintptr_t	serialize(Data *ptr);
		static Data 		*deserialize(uintptr_t raw);
};
