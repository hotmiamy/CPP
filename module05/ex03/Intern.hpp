#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	public:
		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm	*makeForm( std::string name, std::string target);
		AForm	*newShrubberyForm(std::string target);
		AForm	*newRobotomyForm(std::string target);
		AForm	*newPresidentialForm(std::string target);

		class WrongFormException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

#endif /* ********************************************************** INTERN_H */