#include "toyota.h"

Toyota::Toyota()
{
	SetSpeed(100, Weather::Sunny);
	SetSpeed(120,  Weather::Rain);
	SetSpeed(300,  Weather::Snow);
	SetFuelCapacity(200);
	SetFuelConsumption(5);
}

void Toyota::Print()
{
	std::cout << "Car: Toyota\n\tSpeed:\n\t\tSunny: " << GetSpeed()[Weather::Sunny] << "\n\t\tRain: " << GetSpeed()[Weather::Rain] << "\n\t\tSnow: " << GetSpeed()[Weather::Snow] << "\n";
	std::cout << "\tFuel Consumtion: " << GetFuelConsumption() << "\n"; 
	std::cout << "\tFuel Capacity: " << GetFuelCapacity() << "\n"; 
}
