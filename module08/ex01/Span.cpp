#include "Span.hpp"

Span::Span() : _maxSize(0)
{}

Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::~Span() {}

Span Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		this->_vector = rhs._vector;
		this->_maxSize = rhs._maxSize;
	}
	return *this;
}

void	Span::addNumber(int value)
{
	if (this->_vector.size() >= this->_maxSize)
	{
		throw std::runtime_error("Cant add more numbers full capacity");
	}
	this->_vector.insert(_vector.begin(), value);
}

int	Span::shortestSpan()
{
	int diff;
	int	min;

	if (this->_vector.size() < 2)
		throw std::runtime_error("Cannot find span. Insufficient number of elements.");
	std::sort(this->_vector.begin(), this->_vector.end());
	min = this->_vector[1] - this->_vector[0];
	for (size_t i = 1; i < this->_vector.size(); i++)
	{
		diff = this->_vector[i] - this->_vector[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan()
{
	if (this->_vector.size() < 2)
		throw std::runtime_error("Cannot find span. Insufficient number of elements.");
	std::sort(this->_vector.begin(), this->_vector.end());
	return this->_vector.back() - this->_vector.front();
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + this->_vector.size() > this->_maxSize)
		throw std::runtime_error("Adding this range will exceed the capacity of the Span.");
	this->_vector.insert(this->_vector.end(), begin, end);
}
