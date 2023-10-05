#include "BitcoinExchange.hpp"

std::map<std::string, float>		BitcoinExchange::dataBase;
const std::string 					BitcoinExchange::dbFilePath = "./data.csv";
std::ifstream						BitcoinExchange::dbFile;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

void	BitcoinExchange::fillDataBase()
{
	std::string	line;
	std::string	date;
	float		btValue;

	dbFile.open(dbFilePath.data());
	if (!dbFile.is_open())
	{
		std::cout << "Cannot open the file data.csv, check permition" << std::endl;
		std::exit(1);
	}
	while (std::getline(dbFile, line))
	{
		if (line.find_first_of("0123456789") != std::string::npos)
		{
			if (line.find(",") != std::string::npos)
			{
				std::istringstream value(line.substr(line.find(",") + 1));
				value >> btValue;

				dataBase[line.substr(0, line.find(","))] = btValue;
			}
		}
    }
}

void	BitcoinExchange::checkDates(std::string filePath)
{
	std::ifstream	infile;
	std::string		line;
	std::string		date;
	float			btValue;

	infile.open(filePath.data());
	if (!infile.is_open())
	{
		std::cout << "Cannot open " + filePath + " check file name/permition" << std::endl;
		std::exit(1);
	}
	while (std::getline(infile, line))
	{
		if (line.find_first_of("0123456789") != std::string::npos)
		{
			if (!line.find("|"))
			{
				std::cout << "Error: bad input => " + line << std::endl;
				continue ;
			}
			date = line.substr(0, line.find("|"));

			std::tm inDate = {};
			if (strptime(date.c_str(), "%Y-%m-%d", &inDate) == NULL)
				std::cout << "Error: bad input => " + date << std::endl;
			else
			{
				std::istringstream value(line.substr(line.find("|") + 1));
				value >> btValue;

				if (btValue < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (btValue >= std::numeric_limits<int>::max())
					std::cout << "Error: too large a number." << std::endl;
				else
				{
					std::map<std::string, float>::iterator it = dataBase.lower_bound(date);
					if (it == dataBase.begin())
						std::cout << date + ">= " << btValue << " = "  << it->second * btValue << std::endl;
					else
					{
						--it;
						std::cout << date + ">= " << btValue << " = "  << it->second * btValue << std::endl;
					}
				}
			}
		}
	}
}

void BitcoinExchange::run(std::string filePath)
{ 
	fillDataBase();
	checkDates(filePath);
}
