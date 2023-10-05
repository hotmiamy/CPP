#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(PmergeMe const &obj)
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &obj)
{
	if (this != &obj)
	{
		
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::callVecMerge(int argSize, const char **args)
{
	Vec vector;

	for (int i = 1; i < argSize; i++)
		vector.getSequence(args[i]);
	std::cout << "Befeore: ";
	printElements(vector.vec);
	vector.createPairs();
	vector.sortPairs();
	vector.insertMainChain();

	std::cout << "after: ";
	printElements(vector.MainChain);
	std::cout << "The time to procesess a range of " << vector.vec.size();
}

void PmergeMe::callDequeMerge(int argSize, const char **args)
{
	Deque deque;

	for (int i = 1; i < argSize; i++)
		deque.getSequence(args[i]);
	std::cout << "Befeore: ";
	printElements(deque.deque);
	deque.createPairs();
	deque.sortPairs();
	deque.insertMainChain();

	std::cout << "after: ";
	printElements(deque.MainChain);
	std::cout << "The time to procesess a range of " << deque.deque.size();
}
