#include "Circuit.h"
#include <iostream>

Circuit::Circuit()
{
}

void Circuit::AddCar(Car *c)
{
	Racers.push_back(c);
}

void Circuit::SetWeather(Weather _w)
{
	w = _w;
}

void Circuit::SetLength(unsigned int len)
{
	lengthOfCircuit = len;
}

void Circuit::ShowFinalRanks()
{
	if(Finished.size() > 0){
		std::cout << "#####################  THE FINAL SCORES #####################\n";
		for(auto x : Finished)
		{
			x->Print();
		}

		std::cout << "#####################   END OF SCORES    #####################\n";
	} else {
		std::cout << "##################### NOBODY FINISHED  #####################\n";
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	if(NotFinished.size() > 0){	
		std::cout << "##################### DIDN'T FINISH SCORES #####################\n";
		for(auto x : NotFinished)
		{
			x->Print();
		}

		std::cout << "#####################    END OF SCORES    #####################\n";
	} else {
		std::cout << "##################### EVERYBODY FINISHED #####################\n";
	}
}

void Circuit::Race()
{
	for(int i = 0; i < Racers.size(); i++)
	{
		switch(w){
			case Weather::Sunny:
				if(Racers[i]->GetFuelCapacity()/(Racers[i]->GetFuelConsumption()*(lengthOfCircuit/100)) == 0)
					NotFinished.push_back(Racers[i]);
				else 
					Finished.push_back(Racers[i]);
				break;
			case Weather::Rain:
				if((Racers[i]->GetFuelCapacity()/(Racers[i]->GetFuelConsumption()*(lengthOfCircuit/100)))/10 == 0)
					NotFinished.push_back(Racers[i]);
				else 
					Finished.push_back(Racers[i]);
				break;
			case Weather::Snow:
				if((Racers[i]->GetFuelCapacity()/(Racers[i]->GetFuelConsumption()*(lengthOfCircuit/100)))/100 == 0)
					NotFinished.push_back(Racers[i]);
				else 
					Finished.push_back(Racers[i]);
				break;
		}
	}
	if(Finished.size() != 0)
		for(int i = 0; i < Finished.size()-1; i++)
			for(int j = i+1; j < Finished.size(); j++)
				if(Finished[i]->GetSpeed()[w] < Finished[j]->GetSpeed()[w])
					std::swap(Finished[i], Finished[j]);

}
