#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR/DESTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("\"Some boring name of a bureaucrat\""), _grade(150)
{
	std::cout << "You created a default bureaucrat with a boring name with grade 150" << std::endl; 
}

Bureaucrat ::Bureaucrat ( const std::string name, size_t grade ) : _name(name), _grade(grade)
{
	std::cout << "The " << YELLOW << name << RESET << " bureaucrat have been created, his grade is " << grade << std::endl;
	if (grade > 150)
		throw GradeTooLowException(name, grade);
	else if (grade < 1)
		throw GradeTooHighException(name, grade);
}

Bureaucrat ::Bureaucrat ( const Bureaucrat  & src ) : _name(src.getName())
{
	*this = src;
}

Bureaucrat ::~Bureaucrat () {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

const Bureaucrat  &Bureaucrat ::operator=( Bureaucrat  const & rhs )
{
	if ( this != &rhs )
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat  const & i )
{
	o << "The Bureaucrat " << i.getName() << " as the grade " << i.getGrade();
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const size_t &Bureaucrat::getGrade() const
{
	return this->_grade;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

/*
** --------------------------------- EXCEPTIONS ----------------------------------
*/

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string name, size_t grade) : _exName(name), _exGrade(grade) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::cerr << YELLOW << this->_exName << RESET << " cant have the Grade " << this->_exGrade;
	return " grade is to high: 1 is the biggest and 150 is the smallest\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string name, size_t grade) : _exName(name), _exGrade(grade) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::cerr << YELLOW << this->_exName << RESET <<  " cant have the Grade " << this->_exGrade;
	return " grade is to low: 150 is the smallest and 1 is the biggest\n";
}

/*
** --------------------------------- MEMBER FUNCTIONS ----------------------------------
*/

void	Bureaucrat::increaseGrade()
{
	std::cout << YELLOW << this->getName() << RESET << " is trying increase his grade" << std::endl;
	if (this->getGrade() - 1 < 1)
		throw GradeTooHighException(this->getName(), this->getGrade() - 1);
	this->_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	std::cout << YELLOW << this->getName() << RESET << " is trying decrease his grade" << std::endl;
	if (this->getGrade() + 1 > 150)
		throw GradeTooLowException(this->getName(), this->getGrade() + 1);
	this->_grade++;
}

/* ************************************************************************** */