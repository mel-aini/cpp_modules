#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	
	{
		// AAnimal *Aa = new AAnimal();
	}

	// construct objects
	const int length = 4;
	AAnimal** animals = new AAnimal*[length];

	int i = 0;
	while (i < length / 2) {
		animals[i] = new Cat();
		i++;
	}
	while (i < length) {
		animals[i] = new Dog();
		i++;
	}
	
	for (int i = 0; i < length; i++) {
		animals[i]->makeSound();
	}

	// destruct objects
	for (int i = 0; i < length; i++) {
		delete animals[i];
	}
	delete[] animals;
	return 0;
}
