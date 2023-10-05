#include "Bureaucrat.hpp"

void	upSeparetor(std::string str)
{
	std::cout << std::endl << GREEN << std::string(30, '-') << str << std::string(30, '-') << RESET << std::endl << std::endl;
}

int	main( void )
{
	{
		upSeparetor("NO ERRORS/COPY TESTS");
		try
		{
			const Bureaucrat b1("josias", 1);
			const Bureaucrat b2("mane", 150);
			Bureaucrat b3(b1);
			Bureaucrat b4;
			b4 = b2;
			std::cout << b1 << std::endl;
			std::cout << b2 << std::endl;
			b3.decreaseGrade();
			std::cout << b3 << std::endl;
			b4.increaseGrade();
			std::cout << b4 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		upSeparetor("TO HIGHT GRADE TEST");
		try
		{
			const Bureaucrat b1("jacinto", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
		{
		upSeparetor("TO LOW GRADE TEST");
		try
		{
			Bureaucrat b1("jose", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		upSeparetor("INCREASE TO HIGHT GRADE TEST");
		try
		{
			Bureaucrat b1("Osvaldo", 1);
			b1.increaseGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		upSeparetor("DECREASE TO LOW GRADE TEST");
		try
		{
			Bureaucrat b1("vania", 150);
			b1.decreaseGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
