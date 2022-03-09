#include <iostream>
#include "Math.h"

int main()
{
	std::cout << Math::Add(1,2) << " ";
	std::cout << Math::Add(5, 1, 2, 3, 4, 100) << " ";
	std::cout << Math::Add("OOP is fun and... ", "I like C++") << std::endl;
	return 0;
}
