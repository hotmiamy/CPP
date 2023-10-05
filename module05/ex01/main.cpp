#include "Bureaucrat.hpp"
#include "Form.hpp"

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
			Bureaucrat b1("jose", 1);
			const Form f1("Form_A", 1, 1);
			const Form f2("Form_B", 150, 150);
			Form f3(f1);
			Form f4;
			f4 = f2;
			b1.signForm(f4);
			std::cout << f4 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		upSeparetor("TO HIGHT GRADE AND EXEC TEST");
		try
		{
			const Form f1("Form_A", 0, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		upSeparetor("TO LOW EXEC TEST");
		try
		{
			Form f1("Form_A", 150, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		upSeparetor("INCREASE TO HIGHT EXEC TEST");
		try
		{
			Form f1("Form_A", 1, 0);
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
			Form f1("Form_A", 151, 150);
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
			Form f1("Form_A", 0, 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			upSeparetor("TRY TO SIGNED ERROR");
			Bureaucrat b1("Osvaldo", 2);
			Form f1("form_A", 1, 1);
			b1.signForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
