#include "ford.h"

Ford::Ford()
{
	SetSpeed(100, Weather::Sunny);
	SetSpeed(120,  Weather::Rain);
	SetSpeed(300,  Weather::Snow);
	SetFuelCapacity(200);
	SetFuelConsumption(5);
}

void Ford::Print()
{
	std::cout << "Car: Ford\n\tSpeed:\n\t\tSunny: " << GetSpeed()[Weather::Sunny] << "\n\t\tRain: " << GetSpeed()[Weather::Rain] << "\n\t\tSnow: " << GetSpeed()[Weather::Snow] << "\n";
	std::cout << "\tFuel Consumtion: " << GetFuelConsumption() << "\n"; 
	std::cout << "\tFuel Capacity: " << GetFuelCapacity() << "\n"; 
}
