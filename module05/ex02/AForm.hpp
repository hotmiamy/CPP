#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSign;
		const size_t		_sig;
		const size_t		_exec;

	public:
		AForm ();
		AForm ( std::string name, size_t sigGrade, size_t execGrade );
		AForm( AForm const & src );
		virtual ~AForm () = 0;

		AForm &		operator=( AForm const & rhs );

		const std::string	&getName () const;
		const bool			&getIsSig () const;
		const size_t		&getSigGrade () const;
		const size_t		&getExecGrade () const;

		void				beSigned (Bureaucrat const &bureau);
		virtual void		execute (Bureaucrat const &execute) const = 0;

		class GradeTooHighException : public std::exception
		{
			private:
				const std::string	_exName;
				const size_t		_exGrade;
				const size_t		_exExec;	

			public:
				GradeTooHighException(std::string name, size_t exec, size_t grade);
				virtual ~GradeTooHighException() throw();
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				const std::string	_exName;
				const size_t		_exGrade;
				const size_t		_exExec;
				const bool			_trySig;
			public:
				GradeTooLowException(std::string name, size_t grade, size_t exec, bool trySig);
				virtual ~GradeTooLowException() throw();
				virtual const char*	what() const throw();
		};
		class NotSignedException : public std::exception
		{
			private:
				virtual const char*	what() const throw();
		};

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif