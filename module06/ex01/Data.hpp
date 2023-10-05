#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

struct Data
{
	int			_value;
	std::string	_name;

	Data(int value, const char *name);
	~Data();
	Data( Data const &src );
	Data &operator=( Data const &rhs );
};

#endif