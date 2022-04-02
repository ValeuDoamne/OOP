#pragma once

#include <vector>
#include "../weather.h"

class Car
{
	unsigned int fuelCapacity, fuelConsumption;
	std::vector<int> speedAvrg;
public:
	Car()
	{
		speedAvrg.push_back(0);
		speedAvrg.push_back(0);
		speedAvrg.push_back(0);
	}
	virtual void SetSpeed(int _speed, Weather w = Weather::Sunny)
	{
		
		speedAvrg[w] = _speed;
	}
	
	virtual void SetFuelCapacity(int _cap)
	{
		fuelCapacity = _cap;
	}
	
	virtual void SetFuelConsumption(int _con)
	{
		fuelConsumption = _con;
	}
	
	virtual std::vector<int> GetSpeed() const
	{
		return speedAvrg;		
	}
	
	virtual unsigned int GetFuelConsumption() const
	{
		return fuelConsumption;
	}
	
	virtual unsigned int GetFuelCapacity() const
	{
		return fuelCapacity;
	}

	virtual void Print() = 0;
};

