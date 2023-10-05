#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		size_t				_grade;

	public:
		Bureaucrat ();
		Bureaucrat (const std::string name, size_t	grade);
		Bureaucrat ( Bureaucrat  const & src );
		~Bureaucrat ();

		const Bureaucrat				&operator=( Bureaucrat  const & rhs );

		const std::string		&getName() const;
		const size_t			&getGrade() const;

		class GradeTooHighException : public std::exception
		{
			private:
				const std::string	_exName;
				const size_t		_exGrade;			
			public:
				GradeTooHighException(std::string name, size_t grade);
				virtual ~GradeTooHighException() throw();
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				const std::string	_exName;
				const size_t		_exGrade;
			public:
				GradeTooLowException(std::string name, size_t grade);
				virtual ~GradeTooLowException() throw();
				virtual const char*	what() const throw();
		};

		void	increaseGrade();
		void	decreaseGrade();
		void	signForm(Form &form);
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat  const & i );

#endif