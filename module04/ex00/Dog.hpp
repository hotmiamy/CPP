#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
	// Constructors
		Dog();
		Dog(Dog const &copy);
	
	// Destructor
		~Dog();

	// Operators
		Dog &	operator=(const Dog &assign);
	
	//Member Functions
		void	makeSound() const;
};

#endif
