#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>	//cout
#include <map>		//map
#include <fstream>	//ifstrem
#include <cstdlib>	//exit
#include <ctime>	//
#include <sstream>	//isstringstream
#include <limits>

class BitcoinExchange
{
	private:
		static std::map<std::string, float>			dataBase;
		static const std::string					dbFilePath;
		static std::ifstream						dbFile;

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		BitcoinExchange&					operator=(const BitcoinExchange& rhs);

	public:
		static void							run(std::string filePath);
	private:
		static void							fillDataBase();
		static void							checkDates(std::string filePath);
		

};

#endif