#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <list>
#include <sstream>

class RPN
{
	private:
		static const std::string 		tokens;
		static std::list<unsigned int> operands;

	private:
		RPN();
		~RPN();
	public:
		static void run(std::string input);
};

#endif
