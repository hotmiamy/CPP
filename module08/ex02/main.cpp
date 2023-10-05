#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>

int main()
{
	std::cout << "MUTANT STACK" << std::endl;
	{
		MutantStack<int>	mstack;
		MutantStack<int>	mstack3;

		mstack.push(5);
		mstack.push(17);
		mstack3 = mstack;
		std::cout << mstack.top() << std::endl;
		std::cout << mstack3.top() << std::endl;
		mstack.pop();
		mstack3 = mstack;
		std::cout << mstack.size() << std::endl;
		std::cout << mstack3.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "LIST STACK" << std::endl;
	{
		std::list<int> lstack;

		lstack.push_back(5);
		lstack.push_back(17);
		std::cout << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << lstack.size() << std::endl;
		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);

		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << "VECTOR STACK" << std::endl;
	{
		std::vector<int> vstack;

		vstack.push_back(5);
		vstack.push_back(17);
		std::cout << vstack.back() << std::endl;
		vstack.pop_back();
		std::cout << vstack.size() << std::endl;
		vstack.push_back(3);
		vstack.push_back(5);
		vstack.push_back(737);
		vstack.push_back(0);

		std::vector<int>::iterator it = vstack.begin();
		std::vector<int>::iterator ite = vstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << "DEQUE STACK" << std::endl;
	{
		std::deque<int> dstack;

		dstack.push_back(5);
		dstack.push_back(17);
		std::cout << dstack.back() << std::endl;
		dstack.pop_back();
		std::cout << dstack.size() << std::endl;
		dstack.push_back(3);
		dstack.push_back(5);
		dstack.push_back(737);
		dstack.push_back(0);

		std::deque<int>::iterator it = dstack.begin();
		std::deque<int>::iterator ite = dstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(dstack);
	}
	return 0;
}