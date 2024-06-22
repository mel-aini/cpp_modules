#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& S) {
    *this = S;
}

Serializer& Serializer::operator= (const Serializer& C) {
    (void)C;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr) {
	uintptr_t ui = reinterpret_cast<uintptr_t>(ptr);
	return ui;
}

Data 		*Serializer::deserialize(uintptr_t raw) {
	Data *ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}