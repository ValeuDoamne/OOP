#include "Contact.h"
#include "Agenda.h"
#include <iostream>

int main()
{
	Agenda A;
	A.Adauga(new Cunoscut{"Vasile", "07noidoiamandoi"});
	A.Adauga(new Prieten{"Vasile Traian", "1969", "07noidoiamandoi", "Gaiesti"});

	for(auto x : A.GetPrieteni())
		std::cout << x->getName();
}
