#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	// Constructors
		Cat();
		Cat(Cat const &copy);
	
	// Destructor
		~Cat();

	// Operators
		Cat &	operator=(const Cat &assign);
	
	//Member Functions
		void	makeSound() const;
};

#endif
