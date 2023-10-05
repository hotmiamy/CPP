#include <deque>
#include <string>
#

class Deque
{
	public:
		std::deque<int>						deque;
		std::deque<int>						MainChain;

	private:
		std::deque<std::pair<int, int> >	Pairs;
		std::deque<int> 					positions;
		std::deque<int>						PenChain;
		std::deque<int>						JacobSeq;

	public:
		Deque();
		~Deque();

		void	getSequence(std::string input);
		void	createPairs(void);
		void	sortPairs(void);
		void	insertMainChain();
	private:
		void	mergeSort(int left, int right);
		void	merge(int left, int middle, int right);
		void	JacobInsertionSequence();
		void	genPositions();
		int		binarySearch(std::deque<int> array, int target, int begin, int end);
		int		jacobsForm(int n);
};
