#pragma once


class NumberList
{
	int numbers[100];
	int count;
public:
	void Init();
	bool Add(int x);
	
	void Remove(int index);
	bool Insert(int index, int x);
	bool InsertList(int index, int x[], int n);

	void Sort();
	void Print();

	
};
