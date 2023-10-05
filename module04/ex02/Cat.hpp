#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;

	public:
	// Constructors
		Cat();
		Cat(Cat const &copy);
	
	// Destructor
		~Cat();

	// Operators
		Cat &	operator=(const Cat &assign);
	
	// Setters/Getters
		void	setIdea(int inx, std::string ideia) const;
		std::string	getIdea(int inx) const;
	
	//Member Functions
		void	makeSound() const;
};

#endif
