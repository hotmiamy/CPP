#include "Base.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

int main() 
{
	std::cout << GREEN << "CORRECT" << RESET << std::endl;
	{
    	Base* instance = generate();

    	std::cout << "Identifying pointer: ";
    	identify(instance);

    	std::cout << "Identifying reference: ";
    	identify(*instance);
   		delete instance;
	}
	std::cout << GREEN << "ERROR" << RESET << std::endl;
	{
		Base* inst = new Base();

		std::cout << "Identifying pointer: ";
		identify(inst);

		std::cout << "Identifying reference: ";
		identify(*inst);

		delete inst;
	}

    return 0;
}