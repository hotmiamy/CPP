#include "iter.hpp"

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'l', 'u', 'c', 'a', 's'};
	std::string str = "llopes-n";

    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
    size_t charLength = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Printing intArray: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    std::cout << "Printing doubleArray: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;

    std::cout << "Printing charArray: ";
    iter(charArray, charLength, printElement<char>);
    std::cout << std::endl;

	std::cout << "Printing string: ";
    iter(str.c_str(), str.size(), printElement<char>);
    std::cout << std::endl;

	return 0;
}