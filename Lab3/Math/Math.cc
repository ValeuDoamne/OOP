#include <cstring>
#include <cstdarg>
#include "Math.h"


int Math::Add(int a,int b)
{
	return a+b;
}


int Math::Add(int a,int b,int c)
{
	return a+b+c;
}
int Math::Add(double a,double b)
{
	return a+b;
}
int Math::Add(double a,double b,double c)
{
	return a+b+c;
}
int Math::Mul(int a,int b,int c)
{
	return a*b*c;
}
int Math::Mul(double a,double b,double c)
{
	return a*b*c;
}
int Math::Add(int count,...) { // sums up a list of integers
	va_list L;
	va_start(L, count);
	int x = 0;

	for(int i = 0; i < count; i++)
	{
		x += va_arg(L, int);
	}
	va_end(L);
	return x;
}

char* Math::Add(const char *s1, const char *s2)
{
	if(s1 == nullptr || s2 == nullptr)
		return nullptr;
	
	char *s = new char[strlen(s1)+strlen(s2)+1];
	strcpy(s, s1);
	strcat(s,s2);
	return s;
}

