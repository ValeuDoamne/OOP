#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if(count >= 100)
		return false;
	this->numbers[this->count++] = x;
	return true;
}

void NumberList::Sort()
{
	for(int i = 0; i < this->count; i++)
		for(int j = i+1; j < this->count; j++)
			if(this->numbers[i] > this->numbers[j])
				std::swap(this->numbers[i], this->numbers[j]);
}

void NumberList::Print()
{
	for(int i = 0; i < this->count; i++)
		std::cout << this->numbers[i] << ' '; 
	std::cout << std::endl;
}

void NumberList::Remove(int index)
{
	for(int i = index; i < this->count; i++)
		this->numbers[i] = this->numbers[i+1];
	this->count--;
}

bool NumberList::Insert(int index, int x)
{
	if(count >= 100)
		return false;

	for(int i = count; i >= index; i--)
		numbers[i] = numbers[i-1];
	numbers[index] = x;
	count++;

	return true;
}

bool NumberList::InsertList(int index, int x[], int n)
{
	if(count+n >= 100)
		return false;
	for(int i = count-1; i >= index; i--)
		numbers[i+n] = numbers[i];
	for(int i = index; i < n+index; i++)
		numbers[i] = x[i-index];
	count += n;
	return true;
}
