#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	// Constructors
		WrongCat();
		WrongCat(WrongCat const &copy);
	
	// Destructor
		~WrongCat();

	// Operators
		WrongCat &	operator=(const WrongCat &assign);
	
	//Member Functions
		void	makeSound() const;
};

#endif
