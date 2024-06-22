#pragma once
#include <vector>
#include <iterator>
#include <iostream>

class Span
{
	private:
		unsigned int		max;
		std::vector<int>	span;

	public:
		Span();
		Span(unsigned int max);
		Span(const Span& B);
		Span& operator= (const Span& B);
		~Span();

		void	addNumber(int nbr);
		int		shortestSpan();
		int		longestSpan();

		unsigned int		getMax() const;
		std::vector<int>	getSpan() const;

		void	addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
