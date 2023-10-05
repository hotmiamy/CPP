#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <utility> //std::makepair
#include <list>	// std::list
#include <iostream>	// std::cout, std::endl
#include <algorithm>	// std::sort
#include <iterator> //std::iterator
#include <cstdlib>	// std::exit
#include <cmath>	// std::pow
#include "Vec.hpp"
#include "Deque.hpp"

class  PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &obj);

		void	callVecMerge(int argSize, const char **args);
		void	callDequeMerge(int argSize, const char **args);
};

#endif