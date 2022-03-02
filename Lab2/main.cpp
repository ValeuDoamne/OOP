#include <iostream>
#include "NumberList.h"

int main()
{
	NumberList p;
	int x[] = {1, 2, 3, 4};	
	p.Init();

	p.Add(10);
	p.Add(20);
	p.Print();
	p.Remove(1);
	p.Print();
	
	p.InsertList(1, x, 4);
	p.Add(300);
	p.Add(2);

	p.Print();
	p.Sort();
	p.Print();
	return 0;
}
