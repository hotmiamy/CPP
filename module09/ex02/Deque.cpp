#include "Deque.hpp"
#include "debug.hpp"
#include <sstream>	// std::stringstream
#include <iostream>	// std::cout, std::endl
#include <cstdlib>	// std::exit

Deque::Deque()
{
}

Deque::~Deque()
{
}

void Deque::getSequence(std::string input)
{
	std::stringstream iss(input);
	std::string token;
	long int num;

	while (iss >> token)
	{
		if (token.find_first_not_of("0123456789+") != std::string::npos)
		{
			std::cout << "Invalid input: " + token << std::endl;
			std::exit(-1);
		}
		else
		{
			num = std::strtol(token.c_str(), NULL, 10);
			this->deque.push_back(num);
		}
	}
}

void Deque::createPairs(void)
{
	int inx = 0;
	int size = this->deque.size() / 2;

	while (size != 0)
	{
		if (this->deque[inx] < this->deque[inx + 1])
			std::swap(this->deque.at(inx), this->deque.at(inx + 1));
		this->Pairs.push_back(std::make_pair(this->deque.at(inx), this->deque.at(inx + 1)));
		inx += 2;
		size--;
	}
}

void Deque::sortPairs(void)
{
	mergeSort(0, Pairs.size() - 1);
	this->MainChain.push_back(this->Pairs[0].second);
	for (size_t inx = 0; inx < this->Pairs.size(); inx++)
	{
		this->MainChain.push_back(this->Pairs[inx].first);
		this->PenChain.push_back(this->Pairs[inx].second);
	}
}

void Deque::mergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        // Ordena a metade esquerda
        mergeSort(left, middle);
        // Ordena a metade direita
        mergeSort(middle + 1, right);
        // Mescla as duas metades ordenadas
        merge(left, middle, right);
    }
}

void Deque::merge(int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;	
	std::deque<std::pair<int, int> > leftTemp(n1);
	std::deque<std::pair<int, int> > rightTemp(n2);	
	for (int i = 0; i < n1; ++i){
	    leftTemp[i] = Pairs[left + i];
	}
	for (int j = 0; j < n2; ++j){
	    rightTemp[j] = Pairs[middle + 1 + j];
	}	
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftTemp[i].first <= rightTemp[j].first) {
			Pairs[k] = leftTemp[i];
			++i;
		} else {
			Pairs[k] = rightTemp[j];
			++j;
		}
		++k;
	}	
	while (i < n1) {
		Pairs[k] = leftTemp[i];
		++i;
		++k;
	}
	while (j < n2) {
		Pairs[k] = rightTemp[j];
		++j;
		++k;
	}
}

int Deque::binarySearch(std::deque<int> array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void Deque::insertMainChain()
{
	std::deque<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount;
	size_t pos;

	this->genPositions();
	addedCount = 0;

	for (it = this->positions.begin(); it < this->positions.end(); it++)
	{
		target = this->PenChain.at(*it - 1);

		endPos = *it + addedCount;
		pos = this->binarySearch(this->MainChain, target, 0, endPos);
		this->MainChain.insert(this->MainChain.begin() + pos, target);
		addedCount++;
	}
	if (this->deque.size() % 2 != 0)
	{
		target = this->deque.at(this->deque.size() - 1);
		pos = this->binarySearch(this->MainChain, target, 0, this->MainChain.size() - 1);
		this->MainChain.insert(this->MainChain.begin() + pos, target);
	}
}

void Deque::genPositions()
{
	size_t val;
	size_t pos;
	size_t lastPos;
	size_t i;

	if (this->PenChain.empty())
		return;
	this->JacobInsertionSequence();
	lastPos = 1;
	val = 1;
	i = 0;
	while (i < this->JacobSeq.size())
	{
		val = this->JacobSeq.at(i);

		this->positions.push_back(val);

		pos = val - 1;
		while (pos > lastPos)
		{
			this->positions.push_back(pos);
			pos--;
		}
		lastPos = val;
		i++;
	}
	while (val++ < this->PenChain.size())
		this->positions.push_back(val);
}

void Deque::JacobInsertionSequence()
{
	size_t size;
	size_t jcobstalIndex;
	int index;

	size = this->PenChain.size();
	index = 3;

	while ((jcobstalIndex = this->jacobsForm(index)) < size - 1)
	{
		this->JacobSeq.push_back(jcobstalIndex);
		index++;
	}
}

int Deque::jacobsForm(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsForm(n - 1) + 2 * jacobsForm(n - 2));
}
