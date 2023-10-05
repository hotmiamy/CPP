#include <iostream>
#include <cctype>

void	PrintToUpper(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		std::cout << (char)toupper(str[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			PrintToUpper(argv[i]);
		std::cout << std::endl;
	}
}
