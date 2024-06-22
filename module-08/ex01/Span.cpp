#include "Span.hpp"

Span::Span() : max(0) {}

Span::~Span() {}

Span::Span(unsigned int max) : max(max) {}

Span::Span(const Span& B) {
	*this = B;
}

Span& Span::operator= (const Span& B) {
	if (this != &B) {
		this->max = B.getMax();
		this->span = B.getSpan();
	}
	return *this;
}

unsigned int		Span::getMax() const {
	return this->max;
}

std::vector<int>	Span::getSpan() const {
	return this->span;
}

void Span::addNumber(int nbr) {
	if (this->span.size() == this->max)
		throw "Already filled out";
	this->span.push_back(nbr);
}

int Span::shortestSpan() {
	if (span.size() < 2)
		throw "Invalid size";

	int shortest_span = 0;

	std::sort(span.begin(), span.end());

	shortest_span = std::abs(*span.begin() - *(span.begin() + 1));

	for (std::vector<int>::iterator it = span.begin(); it != span.end(); it++) {
		if ((it + 1) == span.end())
			break;

		int tmp = std::abs(*it - *(it + 1));

		if (tmp < shortest_span)
			shortest_span = tmp;
	}
	return shortest_span;
}

int Span::longestSpan() {
	if (span.size() < 2)
		throw "Invalid size";
	
	std::sort(span.begin(), span.end());
	return std::abs(*span.begin() - *(span.end() - 1));
}

void	Span::addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	int size = end - begin;

	// std::cout << "size to add: " << size << std::endl;
	// std::cout << "remaining size : " << max - span.size() << std::endl;
	if ((unsigned long)size > (max - span.size()))
		throw "Insufficiant storage";


	span.insert(span.begin() + span.size(), begin, end);
}