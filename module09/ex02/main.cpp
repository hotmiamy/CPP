#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, const char **argv)
{
	PmergeMe	merge;
	clock_t		vecTime;
	clock_t		dequeTime;

	if (argc == 1)
	{
		std::cout << "Usage: " << argv[0] << " [positive number] [positive number]" << std::endl;
		return (1);
	}
	vecTime = clock();
	merge.callVecMerge(argc, argv);
	vecTime = clock() - vecTime;

	std::cout << " elements with std::vector is " << (float)vecTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl << std::endl;

	dequeTime = clock();
	merge.callDequeMerge(argc, argv);
	dequeTime = clock() - dequeTime;

	std::cout << " elements with std::deque is " << (float)dequeTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	return (0);
}
