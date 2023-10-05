#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T, class Container = std::deque<T> >
class  MutantStack : public std::stack<T>
{
	public:
		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	public:
		MutantStack(){};
		~MutantStack(){};
		MutantStack(const MutantStack& copy) : std::stack<T>(copy)
		{
			*this = copy;
		}

		MutantStack&	operator=(const MutantStack& rhs)
		{
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		const_iterator begin() const {return this->c.begin();}
		const_iterator end() const {return this->c.end();}
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
		const_reverse_iterator rbegin() const {return this->c.rbegin();}
		const_reverse_iterator rend() const {return this->c.rend();}
};

#endif
