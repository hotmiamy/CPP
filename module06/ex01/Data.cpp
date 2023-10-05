#include "Data.hpp"

Data::Data(int value, const char *name) : _value(value), _name(name) {}

Data::~Data() {}

Data::Data( Data const &src) 
{
	*this = src;
}

Data &Data::operator=( Data const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_value = rhs._value;
	}
	return *this;
}
