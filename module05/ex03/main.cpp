#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	upSeparetor(std::string str)
{
	std::cout << std::endl << GREEN << std::string(30, '-') << str << std::string(30, '-') << RESET << std::endl << std::endl;
}

int	main( void )
{
	{
		upSeparetor("NO ERRORS");
		try
		{
			Bureaucrat b1("jose", 1);
			AForm *f1 = Intern().makeForm("robotomy request", "bender");
			AForm *f2 = Intern().makeForm("shrubbery creation", "home");
			AForm *f3 = Intern().makeForm("presidential pardon", "lopes");
			b1.signForm(*f1);
			b1.signForm(*f2);
			b1.signForm(*f3);
			std::cout << *f1 << std::endl;
			std::cout << *f2 << std::endl;
			std::cout << *f3 << std::endl;
			b1.executeForm(*f1);
			b1.executeForm(*f2);
			b1.executeForm(*f3);

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
		upSeparetor("NO EXIST FORM");
		try
		{
			Bureaucrat b1("vivaldo", 150);
			const AForm *f1 = Intern().makeForm("wrong fomr", "error");
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
