#include "Agenda.h"
#include "Contact.h"
#include <vector>
#include <string.h>

Contact* Agenda::Cauta(std::string nume)
{
	for(auto x : this->contacte)
	{
		if(x->getName() == nume)
			return x;
	}
	return nullptr;
}

std::vector<Contact *> Agenda::GetPrieteni()
{
	std::vector<Contact *> prieten;
	for(auto x : this->contacte)
	{
		if(x->getTip() == "Prieten")
			prieten.push_back(x);
	}
	return prieten;
}

void Agenda::Sterge(std::string nume)
{
	for(int i = 0; i < contacte.size(); i++)
	{
		if(contacte[i]->getName() == nume){
			std::vector<Contact *>::iterator it = contacte.begin();
			std::advance(it, i);
			contacte.erase(it);
			i--;
		}
	}
}



void Agenda::Adauga(Contact *C)
{
	contacte.push_back(C);
}
