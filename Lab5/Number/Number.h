#include <string>

class Number
{
	int sign;
	unsigned int base;

	std::string num;
public:
	Number(const char * value,unsigned int base); // where base is between 2 and 16
	Number(const Number& n);
	Number(const int num);
	Number();
	~Number();
	// add operators and copy/move constructor
	void SwitchBase(unsigned int newBase);
	void Print();
	int  GetDigitsCount() const; // returns the number of digits for the current number
	int  GetBase() const; // returns the current base

	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);


	Number& operator=(const Number& n);
	Number& operator=(const int num);
	Number& operator=(const char* num);

	bool    operator>(const Number& n) const;
	bool    operator>=(const Number& n) const;
	bool    operator<=(const Number& n) const;
	bool    operator<(const Number& n) const;
	bool    operator==(const Number& n) const;
	bool    operator!=(const Number& n) const;
	
	char    operator[](const unsigned int index) const;

	Number& operator+=(const Number& n);
	Number& operator+=(const int num);
	Number& operator-=(const Number& n);
	Number& operator-=(const int num);

	Number& operator--();
	Number& operator--(int);
};
