#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
			AForm *f1 = new ShrubberyCreationForm("work");
			AForm *f2 = new RobotomyRequestForm("marvin");
			AForm *f3 = new PresidentialPardonForm(b1.getName());
			AForm *f4;
			b1.signForm(*f1);
			b1.signForm(*f2);
			b1.signForm(*f3);
			f4 = f2;
			std::cout << *f1 << std::endl;
			std::cout << *f2 << std::endl;
			std::cout << *f3 << std::endl;
			std::cout << *f4 << std::endl;
			b1.executeForm(*f1);
			b1.executeForm(*f3);
			b1.executeForm(*f4);

			delete f1;
			delete f2;
			delete f3;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		upSeparetor("EXEC TEST SHRUBBERY GRADE NOT HIGH ENOUGH");
		try
		{
			Bureaucrat b1("vivaldo", 150);
			const AForm *f1 = new ShrubberyCreationForm("home");
			b1.executeForm(*f1);
			delete f1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		upSeparetor("EXEC TEST ROBOTOMY GRADE NOT HIGH ENOUGH");
		try
		{
			Bureaucrat b1("vivaldo", 150);
			const AForm *f1 = new RobotomyRequestForm("marvin");
			b1.executeForm(*f1);
			delete f1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		upSeparetor("EXEC TEST PRESIDENTIAL GRADE NOT HIGH ENOUGH");
		try
		{
			Bureaucrat b1("vivaldo", 150);
			const AForm *f1 = new PresidentialPardonForm("vivaldo");
			b1.executeForm(*f1);
			delete f1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		upSeparetor("EXEC TEST FORM NOT SIGNED");
		try
		{
			Bureaucrat b1("vivaldo", 1);
			const AForm *f1 = new PresidentialPardonForm("vivaldo");
			b1.executeForm(*f1);
			delete f1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return 0;
}
