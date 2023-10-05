#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		std::vector<int>	_vector;
		unsigned int		_maxSize;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		~Span();

		Span	operator=(const Span& rhs);

		void	addNumber(int value);
		int		shortestSpan();
		int		longestSpan();
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
