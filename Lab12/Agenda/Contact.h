#pragma once

#include <string>

class Contact
{
protected:
	std::string name;
public:
	Contact(std::string name): name(name) { }
	std::string getName() const 
	{
		return this->name;
	}
	virtual std::string getTip() const
	{
		return "Contact";
	}
};

class Prieten : public Contact
{
	std::string birthDate, phoneNumber, address;
public:
	Prieten(std::string name, std::string a, std::string b, std::string c) : Contact(name), birthDate(a), phoneNumber(b), address(c) { }
	std::string getBirthDate() const 
	{
		return this->birthDate;
	}
	std::string getPhoneNumber() const 
	{
		return this->phoneNumber;
	}
	std::string getAddress() const 
	{
		return this->address;
	}
	virtual std::string getTip() const
	{
		return "Prieten";
	}
};

class Cunoscut : public Contact
{
	std::string phoneNumber;
public:
	Cunoscut(std::string name, std::string b) : Contact(name), phoneNumber(b) { }
	std::string getPhoneNumber() const 
	{
		return this->phoneNumber;
	}
	virtual std::string getTip() const
	{
		return "Cunoscut";
	}
};



class Coleg : public Contact
{
	std::string serviciu, phoneNumber, address;
public:
	Coleg(std::string name, std::string b, std::string c) : Contact(name), phoneNumber(b), address(c) { }
	std::string getServiciu() const 
	{
		return this->serviciu;
	}
	std::string getPhoneNumber() const 
	{
		return this->phoneNumber;
	}
	std::string getAddress() const 
	{
		return this->address;
	}
	virtual std::string getTip() const
	{
		return "Coleg";
	}
};
