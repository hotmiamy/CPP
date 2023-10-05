#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <string>
# include <iomanip>
# include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

	public:
		ScalarConverter &		operator=( ScalarConverter const & rhs );

		static void		converter(std::string toConvert);
	private:
		static void	convertChar(std::string toChar);
		static void	convertInt(std::string toInt);
		static void	convertFloat(std::string toFloat);
		static void	convertDouble(std::string toDouble);
};

#endif /* ************************************************* SCALARCONVERTER_H */