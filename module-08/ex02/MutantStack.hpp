#pragma once
#include <vector>
#include <stack>
#include <iterator>
#include <iostream>
#include <list>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:

	public:
		MutantStack();
		MutantStack(const MutantStack& M);
		MutantStack& operator= (const MutantStack& M);
		~MutantStack();

		typedef typename Container::iterator iterator;

		iterator begin();
		iterator end();
};

template<typename T, class Container >
MutantStack<T, Container>::MutantStack() {}

template<typename T, class Container >
MutantStack<T, Container>::~MutantStack() {}

template<typename T, class Container >
MutantStack<T, Container>::MutantStack(const MutantStack& M) {
	*this = M;
}

template<typename T, class Container >
MutantStack<T, Container>& MutantStack<T, Container>::operator= (const MutantStack& M) {
	(void)M;
	return *this;
}


template<typename T, class Container >
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template<typename T, class Container >
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return this->c.end();
}
