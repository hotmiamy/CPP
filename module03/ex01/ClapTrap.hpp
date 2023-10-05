#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string _name;
		int _hit;
		int _energy;
		int _atkDamage;

	public:
		// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string _name);
		
		// Destructor
		~ClapTrap();
		
		// Operators
		ClapTrap & operator=(const ClapTrap &assign);
		
		// Getters
		std::string	get_name() const;
		int			get_hit() const;
		int			get_energy() const;
		int			get_atkDamage() const;
		
		// Member Functions
		void attack(const std::string& target);
 		void takeDamage(unsigned int amount);
 		void beRepaired(unsigned int amount);
};

#endif