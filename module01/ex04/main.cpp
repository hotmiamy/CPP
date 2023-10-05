#include "notSed.hpp"

int main(int argc, char **argv)
{
	notSed test;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments: only 3 arguments (fileName, s1, s2)" << std::endl;
		return (1);
	}
	if (test.openFiles(argv[1]) == false)
		return (2);
	test.notReplace(argv[2], argv[3]);
	return (0);
}
