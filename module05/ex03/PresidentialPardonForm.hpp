#ifndef  PRESIDENTIALPARDONFORM_HPP
# define  PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class  PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(  PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm &	operator=(  PresidentialPardonForm const & rhs );

		void	execute(Bureaucrat const &executor) const;
};

#endif /* *****************************************  PRESIDENTIALPARDONFORM_H */