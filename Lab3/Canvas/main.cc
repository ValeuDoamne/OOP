#include "Canvas.h"
#include <iostream>

int main()
{
	Canvas C(100, 50);

	C.Clear();
	C.DrawLine(1, 2, 20, 50, '.');
	C.Print();
	getchar();	
	C.Clear();
	C.DrawCircle(6, 10, 5, '.');
	C.Print();
	getchar();	
	
	C.Clear();
	C.DrawRect(1, 6, 10, 40, '.');
	C.Print();
	getchar();	
	return 0;
}
