#pragma once
#include <stack>
#include <sstream>
#include <iostream>

enum {
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION
};

enum {
	PUSH,
	CALC
};

class RPN
{
	private:
		std::stack<int>	stack;
		int				number;
		int				operation;
		

	public:
		RPN();
		RPN(const RPN& R);
		RPN& operator= (const RPN& R);
		~RPN();

		void	calculate(const char * s);
		int		parseData(std::string& data);
};