#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
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
