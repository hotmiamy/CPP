#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int main()
{
    Array<double> arr1(5);
	Array<int>	arr(0);
    Array<char> arr2(3);

    for (unsigned int i = 0; i < arr1.size(); i++) 
        arr1[i] = 3.14 * (i + 1);

    for (unsigned int i = 0; i < arr2.size(); i++) 
        arr2[i] = 'A' + i;

    for (unsigned int i = 0; i < arr1.size(); i++) 
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;

    for (unsigned int i = 0; i < arr2.size(); i++) 
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;

    try 
	{
        std::cout << arr1[10] << std::endl;
    } 
	catch (const std::exception& e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << "SUBJECT MAIN" << std::endl;
 	{
		Array<int> numbers(MAX_VAL);
    	int* mirror = new int[MAX_VAL];
    	srand(time(NULL));
    	for (int i = 0; i < MAX_VAL; i++)
    	{
    	    const int value = rand();
    	    numbers[i] = value;
    	    mirror[i] = value;
    	}
    	//SCOPE
    	{
    	    Array<int> tmp = numbers;
    	    Array<int> test(tmp);
    	}

    	for (int i = 0; i < MAX_VAL; i++)
    	{
    	    if (mirror[i] != numbers[i])
    	    {
    	        std::cerr << "didn't save the same value!!" << std::endl;
    	        return 1;
    	    }
    	}
    	try
    	{
    	    numbers[-2] = 0;
    	}
    	catch(const std::exception& e)
    	{
    	    std::cerr << e.what() << '\n';
    	}
    	try
    	{
    	    numbers[MAX_VAL] = 0;
    	}
    	catch(const std::exception& e)
    	{
    	    std::cerr << e.what() << '\n';
    	}

    	for (int i = 0; i < MAX_VAL; i++)
    	{
    	    numbers[i] = rand();
    	}
    	delete [] mirror;//
    	return 0;
	}
    return 0;
}