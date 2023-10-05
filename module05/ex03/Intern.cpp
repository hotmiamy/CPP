#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::makeForm( std::string name, std::string target)
{
	std::string formStr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*formPTR[3]) (std::string target) = {&Intern::newShrubberyForm, &Intern::newRobotomyForm, &Intern::newPresidentialForm};

	for (size_t i = 0; i < 3; i++)
	{
		if (name == formStr[i])
			return (this->*formPTR[i])(target);
	}
	throw Intern::WrongFormException();
}

AForm *Intern::newShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::newRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::newPresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

/*
** --------------------------------- EXCEPTIONS ----------------------------------
*/

const char*	Intern::WrongFormException::what() const throw()
{
	return "Wrong form name, forms names:(shrubbery creation, robotomy request, presidential pardon)";
}

/* ************************************************************************** */