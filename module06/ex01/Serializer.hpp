#ifndef  SERIALIZER_HPP
# define  SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{

	private:
		Serializer();
		Serializer(  Serializer const & src );
		~Serializer();

	public:
		Serializer &		operator=( Serializer const & rhs );
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif /* *****************************************************  SERIALIZER_H */