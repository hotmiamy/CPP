#ifndef NOTSED_HPP
# define NOTSED_HPP

#include <fstream>
#include <iostream>

class notSed
{
private:
	std::ifstream	infile;
	std::ofstream	outfile;
public:
	notSed();
	~notSed();

	bool openFiles(std::string filePath);
	void notReplace(std::string s1, std::string s2);
};

#endif