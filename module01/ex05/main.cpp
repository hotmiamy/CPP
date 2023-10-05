#include "Harl.hpp"

int main( void )
{
	Harl harl;
	std::string userInput;

	std::cout << "Type a level: " << std::endl << "- debug" << std::endl << "- info" << std::endl << "- warning" << std::endl << "- error" << std::endl;
	std::cin >> userInput;
	harl.complain(userInput);

	return 0;
}