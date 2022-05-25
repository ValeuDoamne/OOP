#pragma once

#include "Contact.h"
#include <vector>
#include <string>

class Agenda
{
	std::vector<Contact *> contacte;
public:
	Contact *Cauta(std::string nume);
	std::vector<Contact *> GetPrieteni();
	void Sterge(std::string Nume);
	void Adauga(Contact *c);
};
