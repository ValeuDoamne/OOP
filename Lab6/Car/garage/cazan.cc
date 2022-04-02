#include "cazan.h"

Cazan::Cazan()
{
	SetSpeed(200, Weather::Sunny);
	SetSpeed(50,  Weather::Rain);
	SetSpeed(5000,  Weather::Snow);
	SetFuelCapacity(10000);
	SetFuelConsumption(1);
}

void Cazan::Print()
{
	std::cout << "Car: Cazan\n\tSpeed:\n\t\tSunny: " << GetSpeed()[Weather::Sunny] << "\n\t\tRain: " << GetSpeed()[Weather::Rain] << "\n\t\tSnow: " << GetSpeed()[Weather::Snow] << "\n";
	std::cout << "\tFuel Consumtion: " << GetFuelConsumption() << "\n"; 
	std::cout << "\tFuel Capacity: " << GetFuelCapacity() << "\n"; 
}
