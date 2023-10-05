#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructors
		ScavTrap( void );
		ScavTrap(std::string const & name);
		ScavTrap(const ScavTrap &copy);
		
		// Destructor
		~ScavTrap( void );
		
		// Operators
		ScavTrap &	operator=(const ScavTrap &assign);

		//Member Functions
		void		guardGate();
		void		attack(std::string const &target);
};

#endif