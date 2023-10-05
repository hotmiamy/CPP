#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src.getName(), src.getSigGrade(), src.getExecGrade())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
		this->_target = rhs._target;
	return *this;
}

/*
** --------------------------------- METHODS ---------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	outTree;
	std::string		tree;

	AForm::execute(executor);
	tree = this->_target + "_shrubbery";
	outTree.open(tree.data());
	if (outTree.is_open())
	{
		std::cout << "A tree have been create in " + tree << std::endl;
		tree =  "    oxoxoo    ooxoo\n"
			    "  ooxoxo oo  oxoxooo\n"
 				" oooo xxoxoo ooo ooox\n"
 				" oxo o oxoxo  xoxxoxo\n"
  				"  oxo xooxoooo o ooo\n"
    			"    ooo\\oo\\  /o/o\n"
				"        \\  \\/ /\n"
				"		 |   /\n"
                "         |  |\n"
				"         | D|\n"
				"         |  |\n"
				"         |  |\n"
				"  ______/____\\____\n"
				"Christopher S McDowell\n";
		outTree << tree;
		outTree.close();
	}
	else
		std::cerr << this->getName() + " can execute but can't create the file of the executer (check forder permition)" << std::endl;
}

/* ************************************************************************** */