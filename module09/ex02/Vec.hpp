#include <vector>	// std::vector
#include <string>	// std::string
#include <sstream>	// std::stringstream
#include <iostream>	// std::cout, std::endl
#include <cstdlib>	// std::exit
#include "debug.hpp"

class Vec
{
	public:
		std::vector<int>					vec;
		std::vector<int>					MainChain;

	private:
		std::vector<int> 					positions;
		std::vector<std::pair<int, int> >	Pairs;
		std::vector<int>					PenChain;
		std::vector<int>					JacobSeq;

	public:
		Vec(/* args */);
		~Vec();
		std::vector<int> getVec();

		void	getSequence(std::string input);
		void	createPairs(void);
		void	sortPairs(void);
		void	mergeSort(int left, int right);
		void	merge(int left, int middle, int right);
		void	JacobInsertionSequence();
		void	genPositions();
		void	insertMainChain();
		int		binarySearch(std::vector<int> array, int target, int begin, int end);
		int		jacobsForm(int n);
};
