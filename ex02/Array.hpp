#pragma once
#include <iostream>
#include <exception>

template <class T>
class Array
{
	private:
		T 				*arr;
		unsigned int	length;

	public:
		Array() : arr(NULL), length(0) {}

		Array(const Array& A) {
			arr = NULL;
			*this = A;
		}

		Array& operator= (const Array& A) {
			if (this != &A) {
				length = A.size();
				delete arr;
				arr = new T[length];
				for (unsigned int i = 0; i < length; i++) {
					arr[i] = A.arr[i];
				}
			}
			return *this;
		}

		~Array() {
			delete[] arr;
		}

		Array(unsigned int n) {
			if (n >= 0) {
				arr = new T[n];
			}
			length = n;
		}

		T& operator[](unsigned int index) {
			if (index < 0 || static_cast<unsigned int>(index) >= size())
				throw std::out_of_range("Out of range");
			return arr[index];
		}

		unsigned int size() const {
			return length;
		}
};
