#include "notSed.hpp"

notSed::notSed()
{}


notSed::~notSed()
{
	this->infile.close();
	this->outfile.close();
}

bool notSed::openFiles(std::string filePath)
{
	this->infile.open(filePath.data());
	if (this->infile.fail())
	{
		std::cout << "Cannot open " << "'" << filePath <<  "'" << " check if you have permission or if the file name/path is correct" << std::endl;
		return (false);
	}
	filePath += ".replace";
	this->outfile.open(filePath.data());
	if (!this->outfile.is_open())
	{
		std::cout << "Cannot create " << "'" << filePath <<  "'" << " check if you have permission for write in this forder" << std::endl;
		return (false);
	}
	return (true);
}

void	notSed::notReplace(std::string s1, std::string s2)
{
	std::string buff;

	
	while (std::getline(this->infile, buff))
	{
		while(buff.find(s1) != std::string::npos)
		{
			buff.insert(buff.find(s1), s2);
			buff.erase(buff.find(s1), s1.size());
		}
		this->outfile << buff << std::endl;
	}
}