#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class Animal
{
	protected:
		std::string _type;

	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);

		// Destructor
		virtual ~Animal();
		
		// Operators
		Animal & operator=(const Animal &assign);
		
		// Getters / Setters
		std::string getType() const;
		void		setType(std::string const &type);

		// Member Functions
		virtual void	makeSound() const;
};

#endif
