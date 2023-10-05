#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScalarConverter::converter(std::string converter)
{
	convertChar(converter);
	convertInt(converter);
	convertFloat(converter);
	convertDouble(converter);
}

void ScalarConverter::convertChar(std::string input)
{
	if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0]))
	{
		std::cout << "Char: " << static_cast<char>(input[0]) << std::endl;
		return ;
	}
	if (!input.find("0"))
	{
		if (atoi(input.data()) >= 32 && atoi(input.data()) <= 126)
			std::cout << "Char: " << static_cast<char>(atoi(input.data())) << std::endl;
		else
			std::cout << "Char: No displayable" << std::endl;
		return ;
	}
	if (input.compare("nan") == 0 || input.compare("nanf") == 0 || atoi(input.data()) == 0)
	{
		std::cout << "Char: Impossible" << std::endl;
		return ;
	}
	if (atoi(input.data()) >= 32 && atoi(input.data()) <= 126)
		std::cout << "Char: " << static_cast<char>(atoi(input.data())) << std::endl;
	else
		std::cout << "Char: No displayable" << std::endl;
}

void	ScalarConverter::convertInt(std::string input)
{
	if (input.size() == 1 || !input.find("0"))
	{
		if (isdigit(input[0]))
			std::cout << "Int: " << static_cast<int>(atoi(input.data())) << std::endl;
		else
			std::cout << "Int: " << static_cast<int>(input[0]) << std::endl;
		return ;
	}
	if (input.compare("nan") == 0 || input.compare("nanf") == 0 || atoi(input.data()) == 0)
	{
		std::cout << "Int: Impossible" << std::endl;
		return ;
	}
	if (atol(input.data()) >= std::numeric_limits<int>::max() || atol(input.data()) <= std::numeric_limits<int>::min())
	{
		std::cout << "Int: Impossible" << std::endl;
		return ;
	}
	std::cout << "Int: " << static_cast<int>(atoi(input.data())) << std::endl;
}

void	ScalarConverter::convertFloat(std::string input)
{
	if (input.size() == 1 || !input.find("0"))
	{
		if (isdigit(input[0]))
			std::cout << std::fixed << std::setprecision(1) << "Float: " << static_cast<float>(atof(input.data())) << "f" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "Float: " << static_cast<float>(input[0]) << "f" << std::endl;
		return ;
	}
	else if (atof(input.data()) == 0)
	{
		std::cout << "Double: impossible" << std::endl;
		return ;
	}
	if (input.compare("nan") == 0 || input.compare("nanf") == 0 )
	{
		std::cout << "Float: nanf" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << "Float: " << static_cast<float>(atof(input.data())) << "f" << std::endl;
}

void	ScalarConverter::convertDouble(std::string input)
{
	if (input.size() == 1 || !input.find("0"))
	{
		if (isdigit(input[0]))
			std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(atof(input.data())) << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(input[0]) << std::endl;
		return ;
	}
	else if (atof(input.data()) == 0)
	{
		std::cout << "Double: impossible" << std::endl;
		return ;
	}
	if (input.compare("nan") == 0 || input.compare("nanf") == 0 )
	{
		std::cout << "Double: nan" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << "Double: " << static_cast<double>(atof(input.data())) << std::endl;
}

/* ************************************************************************** */