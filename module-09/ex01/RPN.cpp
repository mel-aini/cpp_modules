#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::RPN(const RPN& R) {
	*this = R;
}

RPN& RPN::operator= (const RPN& R) {
	if (this != &R) {
		this->stack = R.stack;
		this->number = R.number;
		this->operation = R.operation;
	}
	return *this;
}

RPN::~RPN()
{
}

void	RPN::calculate(const char *s)
{
	std::string			str(s);
	std::stringstream	ss(str);

	while (true) {
		std::string	tmp;
		ss >> tmp;
		if (tmp.empty()) {
			if (stack.size() != 1)
				throw "should more than one element in the stack";
			std::cout << stack.top() << std::endl; 
			break;
		}

		int res = parseData(tmp);

		if (res == PUSH)
			stack.push(number);
		else {
			if (stack.size() < 2)
				throw "at least 2 elements should be in the stack to perform an operation";

			int	right = stack.top();
			stack.pop();
			int	left = stack.top();
			stack.pop();

			int	result = 0;

			switch (operation)
			{
				case ADDITION:
					result = left + right;
					break;
				case SUBTRACTION:
					result = left - right;
					break;
				case MULTIPLICATION:
					result = left * right;
					break;
				case DIVISION:
					if (right == 0)
						throw "You canno't divid by zero";
					result = left / right;
					break;
			}

			stack.push(result);
		}
		
	}
}

int		RPN::parseData(std::string& data)
{
	if (data.length() != 1)
		throw "Error: synthax error";

	if (data[0] >= '0' && data[0] <= '9') {
		std::stringstream ss(data);
		ss >> this->number;
		return PUSH;
	}

	switch (data[0])
	{
		case '+':
			this->operation = ADDITION;
			return CALC;
		case '-':
			this->operation = SUBTRACTION;
			return CALC;
		case '*':
			this->operation = MULTIPLICATION;
			return CALC;
		case '/':
			this->operation = DIVISION;
			return CALC;
		default:
			throw "Error: synthax error";
	}
}