#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(Brain const &copy);
		~Brain();

		Brain		&operator=(const Brain &assing);

		std::string	getIdeas(int inx) const;
		void		setIdea(std::string str, int size);
};

#endif
