#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin ./file" << std::endl;
		return (1);
	}
	BitcoinExchange::run(argv[1]);
	return (0);
}
