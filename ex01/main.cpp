#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const int length = 4;
	Animal** animals = new Animal*[length];

	int i = 0;
	while (i < length / 2) {
		animals[i] = new Cat();
		i++;
	}
	*animals[0] = *animals[1];
	while (i < length) {
		animals[i] = new Dog();
		i++;
	}
	
	for (int i = 0; i < length; i++) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < length; i++) {
		delete animals[i];
	}
	delete[] animals;
	return 0;
}
