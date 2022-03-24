#include "Number.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

Number::Number(const char * value, unsigned int base = 10) // where base is between 2 and 16
{
	if(base < 0 || base > 16)
	{
		std::cerr << "Not a valid base\n";
		exit(0);
	}
	char hex[] = "ABCEF";
	if(base > 10)
		hex[base - 10] = '\0';
	
	this->sign = +1;

	if(value[0] == '-')
	{
		this->sign = -1;
		value++;
	} else if(value[0] == '+')
	{
		value++;
	}
	for(size_t i = 0; i < strlen(value); i++)
	{
		if(value[i] < '0' || (value[i] > (char)('0'+base) && !strchr(hex, value[i]) ))
		{
			std::cerr << "Not a valid number in base " << base << "\n";
			exit(0);
		}
	}

	this->base = base;
	this->num = value;
}

Number::Number(const Number& n)
{
	this->base = n.base;
	this->num.resize(n.num.size());
	this->num  = n.num;
	this->sign = n.sign;
}

Number::Number(const int num)
{
	Number r;
	r = num;
	this->num = r.num;
	this->base = r.base;
	this->sign = r.sign;
}

Number::Number()
{
	this->base = 10;
	this->num  = "0";
	this->sign = +1;
}

Number::~Number()
{
	
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
// Function to convert a number
// from given base to decimal number
int toDeci(std::string str, int base)
{
    // Stores the length
    // of the string
    int len = str.size();
    // Initialize power of base
    int power = 1;
    // Initialize result
    int num = 0;
    // Decimal equivalent is str[len-1]*1
    // + str[len-2]*base + str[len-3]*(base^2) + ...
    for (int i = len - 1; i >= 0; i--) {
        // A digit in input number must
        // be less than number's base
        if (val(str[i]) >= base) {
            printf("Invalid Number");
            return -1;
        }
        // Update num
        num += val(str[i]) * power;
        // Update power
        power = power * base;
    }
 
    return num;
}
 
// Function to return equivalent
// character of a given value
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
// Function to convert a given
// decimal number to a given base
std::string fromDeci(int base, int inputNum)
{
    // Store the result
    std::string res = "";
 
    // Repeatedly divide inputNum
    // by base and take remainder
    while (inputNum > 0) {
 
        // Update res
        res += reVal(inputNum % base);
 
        // Update inputNum
        inputNum /= base;
    }

    std::reverse(res.begin(), res.end());
 
    return res;
}
 
void convertBase(std::string& s, int a, int b)
{
    long long unsigned num = toDeci(s, a);
 
    s = fromDeci(b, num);
}

void Number::SwitchBase(unsigned int newBase)
{
	if(newBase == this->base)
		return;
	convertBase(this->num, this->base, newBase);
	this->base = newBase;
}

void Number::Print()
{
	if(sign > 0)
		std::cout << "Number " << num << " in base " << base << std::endl;
	else
		std::cout << "Number -" << num << " in base " << base << std::endl;
}

Number& Number::operator=(const Number& n)
{
	this->num = n.num;
	this->base = n.base;
	this->sign = n.sign;
	return *this;
}

Number& Number::operator=(const char* v)
{
	Number r(v);
	*this = r;
	return *this;
}

Number& Number::operator=(const int num)
{
	char s[256];
	int cp1, cp2, nc = 0;
	cp1 = cp2 = num;
	while(cp1)
	{
		cp1/=10;
		nc++;
	}
	for(int i = nc-1; i >= 0; i--){
		s[i] = '0' + cp2%10;
		cp2 /= 10;
	}
	s[nc] = '\0';

	Number r(s);

	*this = r;
	return *this;
}

/*
Number& Number::operator=(Number&& n)
{
	memcpy(this, &n, sizeof(Number));
	return *this;
}
*/


Number operator+(const Number& n1, const Number& n2)
{
	Number r("0", 10);
	
	Number n1_cpy(n1), n2_cpy(n2);
	
	n1_cpy.SwitchBase(10); 
	n2_cpy.SwitchBase(10);


	std::string s1 = n1_cpy.num, s2 = n2_cpy.num;

	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	

	int carry = 0, digit = 0;
	

	r.num.resize(std::max(s1.length(), s2.length()) + 1);

	unsigned long int i;
	for(i = 0; i < std::min(s1.length(), s2.length()); i++)
	{
		digit = (s1[i] - '0' + s2[i] - '0' + carry)%r.base;
		r.num[i] = '0' + digit;
		carry = (s1[i] - '0' + s2[i] - '0' + carry)/r.base;
	}
	if(i  == s1.length() - 1)
	{
		for(int j = s1.length(); j < s2.length(); j++)
		{
			r.num[j] = s2[j] + carry;
			carry = 0;
		}
	} else {
		for(int j = s2.length(); j < s1.length(); j++)
		{
			r.num[j] = s1[j] + carry;
			carry = 0;
		}
	}
	if(carry > 0)
		r.num[std::max(s1.length(), s2.length())] = '0' + carry;


	std::reverse(r.num.begin(), r.num.end());
	std::string s = r.num;
	
	convertBase(s, r.base, 10);

	std::cout << "Debug: " << s << std::endl;
	
	return r;
}

Number operator-(const Number& n1,const Number& n2)
{
	Number r("0", 10);
	
	Number n1_cpy(n1), n2_cpy(n2);
	
	n1_cpy.SwitchBase(10); 
	n2_cpy.SwitchBase(10);
	
	if(n1_cpy < n2_cpy)
	{
		r.sign = -1;
		std::swap(n1_cpy, n2_cpy);
	}
	
	std::string s1 = n1_cpy.num, s2 = n2_cpy.num;

	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	

	int borrow = 0, digit = 0;
	
	r.num.resize(std::max(s1.length(), s2.length()) + 1);

	unsigned long int i;
	for(i = 0; i < std::min(s1.length(), s2.length()); i++)
	{
		digit = s1[i] - '0' - (s2[i] - '0') - borrow;
		if(digit < 0)
		{
			digit += r.base;
			borrow = 1;
		} else {
			borrow = 0;
		}
		r.num[i] = '0' + digit;
	}
	if(i  == s1.length() - 1)
	{
		for(int j = s1.length(); j < s2.length(); j++)
		{
			r.num[j] = s2[j] - borrow;
			borrow = 0;
		}
	} else {
		for(int j = s2.length(); j < s1.length(); j++)
		{
			r.num[j] = s1[j] - borrow;
			borrow = 0;
		}
	}
	if(borrow > 0)
		std::cerr << "Something went wrong!\n";
	std::reverse(r.num.begin(), r.num.end());
	
	r.SwitchBase(std::max(n1.base, n2.base));
	
	return r;
}

bool Number::operator==(const Number& n) const
{
	Number x{n};
	x.SwitchBase(this->base);
	if(this->num.length() == x.num.length())
	{
		if(this->sign == x.sign)
		{
			for(int i = this->num.length() - 1; i >= 0; i--)
			{
				if(this->num[i] != x.num[i])
					return false;
			}
			return true;
		}
	}
	return false;
}

bool Number::operator!=(const Number& n) const
{
	return !(*this == n);
}

bool Number::operator>(const Number& n) const
{
	Number x{n};
	x.SwitchBase(this->base);
	if(*this == n)
		return false;
	if(this->num.length() > x.num.length())
	{
		if(this->sign > 0)
			return true;
		else
			return false;
	} else {
		if(x.sign > 0)
			return false;
		else
			return true;
	}
}

bool Number::operator>=(const Number& n) const
{
	return !(*this < n);
}

bool Number::operator<(const Number& n) const
{
	Number x{n};
	x.SwitchBase(this->base);
	return !(*this > n) && (*this != n);
}

bool Number::operator<=(const Number& n) const
{
	return !(*this > n);
}

Number& Number::operator+=(const Number& n)
{
	*this = *this + n;
	return *this;
}

Number& Number::operator+=(const int num)
{
	Number r;
	r = num;
	r.SwitchBase(this->base);
	for(int i = this->num.length(); i < r.num.length(); i++)
		this->num += "0";
	*this = *this + r;
	return *this;
}

Number& Number::operator-=(const Number& n)
{
	*this = *this - n;
	return *this;
}

Number& Number::operator-=(const int num)
{
	Number r;
	r = num;
	r.SwitchBase(this->base);
	for(int i = this->num.length(); i < r.num.length(); i++)
		this->num += "0";
	*this = *this - r;
	return *this;
}

Number& Number::operator--()
{
	this->num.erase(this->num.length() - 1, 1);
	return *this;
}

Number& Number::operator--(int)
{
	
	this->num.erase(0, 1);
	return *this;
}

char    Number::operator[](const unsigned int index) const
{
	return this->num[index];
}
 

int  Number::GetDigitsCount() const { // returns the number of digits for the current number
	return num.length();
}


int  Number::GetBase() const // returns the current base
{
	return base;
}
