#include <iostream>
#include <iterator>

template <typename T>
void	printElements(T element)
{
	typename T::iterator it = element.begin();

	while (it != element.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
template <typename T>
void	printPairElements(T element)
{
	typename T::iterator it = element.begin();

	while (it != element.end())
	{
		std::cout << it->first << " " << it->second << " ";
		it++;
	}
	std::cout << std::endl;
}