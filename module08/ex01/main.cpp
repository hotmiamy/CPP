#include "Span.hpp"
#include <iostream>
#include <ctime>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

int main()
{
	std::cout << GREEN << "CORRECT" << RESET << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		int arr[] = {1,1,3,4,5,7,9,10};
		Span sp = Span(50);
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

		sp.addRange(numbers.begin(), numbers.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try 
	{
    	Span span(10000);
		std::srand(std::time(NULL));
    	for (int i = 1; i <= 10000; ++i)
    		span.addNumber(std::rand());
    	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    	std::cout << "Longest span: " << span.longestSpan() << std::endl;
   	} 
	catch (std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	std::cout << GREEN << "ERROR" << RESET << std::endl;
		try
	{
		Span sp = Span(4);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		int arr[] = {1,1,3,4,5,7,9,10};
		Span sp = Span(7);
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

		sp.addRange(numbers.begin(), numbers.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}