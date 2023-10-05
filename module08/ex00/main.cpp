#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

int main()
{
	{
		std::cout << GREEN << "VECTOR CONTAINER" << RESET << std::endl << std::endl;
		int arr[] = {1,2,3,4,5,6,7,8,9,10};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
    	try 
		{
    	    int valueToFind = 3;
    	    std::vector<int>::iterator result = easyfind(numbers, valueToFind);
    	    std::cout << "Value " << valueToFind << " find in index: " << std::distance(numbers.begin(), result) << std::endl;
    	} catch (const std::exception& e) 
		{
    	    std::cout << "Exception call: " << e.what() << std::endl;
    	}
	}
	{
		std::cout << std::endl;
		std::cout << GREEN << "LIST CONTAINER" << RESET << std::endl << std::endl;
		int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
		std::list<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
		try 
		{
    	    int valueToFind = 40;
    	    std::list<int>::iterator result = easyfind(numbers, valueToFind);
    	    std::cout << "Value " << valueToFind << " find in index: " << std::distance(numbers.begin(), result) << std::endl;
    	} catch (const std::exception& e) 
		{
    	    std::cout << "Exception call: " << e.what() << std::endl;
    	}
	}
	{
		std::cout << std::endl;
		std::cout << GREEN << "SET CONTAINER" << RESET << std::endl << std::endl;
		int arr[] = {1,2,3,4,5,6,7,8,9,10};
		std::set<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
		try 
		{
    	    int valueToFind = 10;
    	    std::set<int>::iterator result = easyfind(numbers, valueToFind);
    	    std::cout << "Value " << valueToFind << " find in index: " << std::distance(numbers.begin(), result) << std::endl;
    	} catch (const std::exception& e) 
		{
    	    std::cout << "Exception call: " << e.what() << std::endl;
    	}
	}
	{
		std::cout << GREEN << "EXCEPTION" << RESET << std::endl << std::endl;
		int arr[] = {1,2,3,4,5,6,7,8,9,10};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
    	try 
		{
    	    int valueToFind = 0;
    	    std::vector<int>::iterator result = easyfind(numbers, valueToFind);
    	    std::cout << "Value " << valueToFind << " find in index: " << std::distance(numbers.begin(), result) << std::endl;
    	} catch (const std::exception& e) 
		{
    	    std::cout <<  RED << "Exception call: " << e.what() << RESET << std::endl;
    	}
	}
    return 0;
}