#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR/DESTRUCTOR --------------------------------
*/

AForm::AForm() : _name("Boring name of a form"), _isSign(false), _sig(150), _exec(150) 
{
	std::cout << "Create form: " << *this << std::endl;
}

AForm::AForm(std::string name, size_t sigGrade, size_t execGrade) : _name(name), _isSign(false), _sig(sigGrade), _exec(execGrade)
{
	std::cout << "Create form: " << *this << std::endl;
	if (sigGrade > 150 || execGrade > 150)
		throw GradeTooLowException(name, sigGrade, execGrade, false);
	if (sigGrade < 1 || execGrade < 1)
		throw GradeTooHighException(name, sigGrade, execGrade);
}

AForm::AForm( const AForm &src ) : _name(src.getName()), _isSign(src.getIsSig()), _sig(src.getSigGrade()), _exec(src.getExecGrade())
{

}

AForm::~AForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSign = rhs.getIsSig();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	std::string issign = (i.getIsSig() == true) ? ": is signed" : " is not signed";

	o << i.getName() 
	<< issign 
	<< ", the form requeried " << i.getSigGrade() 
	<< " to be signed," 
	<< " and " 
	<< i.getExecGrade() << " to execute";
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	&AForm::getName() const {return this->_name;}
const bool			&AForm::getIsSig() const {return this->_isSign;}
const size_t		&AForm::getSigGrade() const {return this->_sig;}
const size_t		&AForm::getExecGrade() const {return this->_exec;}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AForm::beSigned(Bureaucrat const &bureau)
{
	if (this->getSigGrade() < bureau.getGrade())
		throw AForm::GradeTooLowException(this->getName(), this->getSigGrade(), this->getExecGrade(), true);
	this->_isSign = true;
}

void	AForm::execute(Bureaucrat const &execute) const
{
	if (this->getExecGrade() < execute.getGrade())
		throw AForm::GradeTooLowException(this->getName(), this->getSigGrade(), this->getExecGrade(), false);
	if (this->getIsSig() == false)
		throw AForm::NotSignedException();
}

/*
** --------------------------------- EXCEPTIONS ----------------------------------
*/

AForm::GradeTooHighException::GradeTooHighException(std::string name, size_t grade, size_t exec) : _exName(name), _exGrade(grade), _exExec(exec) {}
AForm::GradeTooHighException::~GradeTooHighException() throw(){}

const char* AForm::GradeTooHighException::what() const throw()
{
	std::string str = (this->_exGrade < 1) ? "grade " : "execute ";

	if (this->_exGrade < 1 && this->_exExec < 1)
		std::cerr << YELLOW << this->_exName << RESET <<  " cant have a grade and execute " << this->_exGrade;
	else if (this->_exGrade < 1)
		std::cerr << YELLOW << this->_exName << RESET <<  " cant have a " << str << this->_exGrade;
	else if (this->_exExec < 1)
		std::cerr << YELLOW << this->_exName << RESET <<  " cant have a " << str << this->_exExec;
	return " is to high: 1 is the biggest and 150 is the smallest\n";
}

AForm::GradeTooLowException::GradeTooLowException(std::string name, size_t grade, size_t exec, bool trySig) : _exName(name), _exGrade(grade), _exExec(exec), _trySig(trySig) {}
AForm::GradeTooLowException::~GradeTooLowException() throw(){}

const char* AForm::GradeTooLowException::what() const throw()
{
	std::string str = (this->_exGrade > 150) ? "grade " : "execute ";

	if (this->_exGrade > 150 && this->_exExec > 150)
		std::cerr << YELLOW << this->_exName << RESET <<  " cant have a grade and execute " << this->_exGrade;
	else if (this->_exGrade > 150)
		std::cerr << YELLOW << this->_exName << RESET <<  " cant have a " << str << this->_exGrade;
	else if (this->_exExec > 150)
		std::cerr << YELLOW << this->_exName << RESET <<  " cant have a " << str << this->_exExec;
	else if (this->_trySig == true)
		return " the grade is not high enough to sign";
	else if (this->_trySig == false)
		return " the grade is not high enough to execute";

	return " is to low: 150 is the smallest and 1 is the biggest\n";

}

const char*	AForm::NotSignedException::what() const throw()
{
	return " form is not signed";
}

/* ************************************************************************** */