#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class MyVector{
	int count;
	int x[1024];
public:
	MyVector() : count(0) { }
	bool Add(int y)
	{
		if(count >= 1024)
			return false;
		x[count++] = y;
		return true; 
	}
	bool Delete(int index)
	{
		if(index <= 0 && index >= count)
			return false;
		for(int i = index; i < count; i++)
			x[i] = x[i+1];
		count--;
		return true;
	}
	void Iterate(void (*f)(int &))
	{
		for(int i = 0; i < count; i++)
			f(x[i]);
	}
	void Filter(bool (*f)(int))
	{
		for(int i = 0; i < count; i++)
			if(f(x[i]))
				Delete(i);
	}
	int get(int index) const
	{
		return x[index];
	}
	int size() const 
	{
		return count;
	}
};


int main()
{
	MyVector v;
	v.Add(10);
	v.Add(100);
	v.Add(200);
	v.Filter([](int x){ if(x > 100) return true; else return false;});
	for(int i = 0; i < v.size(); i++)
		std :: cout << v.get(i) << " ";
	std::cout << std::endl;
}
