#include "bembeu.h"

bembeu::bembeu()
{
	SetSpeed(120, Weather::Sunny);
	SetSpeed(50,  Weather::Rain);
	SetSpeed(30,  Weather::Snow);
	SetFuelCapacity(3);
	SetFuelConsumption(1);
}

void bembeu::Print()
{
	std::cout << "Car: Bembeu\n\tSpeed:\n\t\tSunny: " << GetSpeed()[Weather::Sunny] << "\n\t\tRain: " << GetSpeed()[Weather::Rain] << "\n\t\tSnow: " << GetSpeed()[Weather::Snow] << "\n";
	std::cout << "\tFuel Consumtion: " << GetFuelConsumption() << "\n"; 
	std::cout << "\tFuel Capacity: " << GetFuelCapacity() << "\n"; 
}
