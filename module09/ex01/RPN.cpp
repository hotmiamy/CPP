#include "RPN.hpp"

const std::string RPN::tokens = "+-*/";
std::list<unsigned int> RPN::operands;

RPN::RPN() {}

RPN::~RPN() {}

void	RPN::run(std::string input)
{
	std::istringstream iss(input);
	std::string expToken;
	unsigned int *operand[2];

	while (iss >> expToken)
	{
		if (isdigit(expToken[0]))
			operands.push_back(expToken[0] - '0');
		else if (RPN::tokens.find(expToken[0]) != std::string::npos)
		{
			if (operands.size() < 2)
			{
				std::cerr << "Error: Insufficient operands for operation." << std::endl;
				return ;
			}

			operand[1] = &operands.back();
			operands.pop_back();
			operand[0] = &operands.back();
			operands.pop_back();

			unsigned int result = 0;
			if (expToken == "+")
				result = *operand[0] + *operand[1];
			else if (expToken == "-")
				result = *operand[0] - *operand[1];
			else if (expToken == "*")
				result = *operand[0] * *operand[1];
			else if (expToken == "/")
			{
				if (operand[1] == 0)
				{
					std::cerr << "Error: Division by zero." << std::endl;
					return ;
				}
				result = *operand[0] / *operand[1];
			}
			operands.push_back(result);
		}
		else
		{
			std::cerr << "Error: Invalid token." << std::endl;
			return ;
		}
	}
	std::cout << "result: " << operands.back() << std::endl;
}