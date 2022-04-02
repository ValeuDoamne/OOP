#include <vector>
#include "garage/Car.h"
#include "garage/allcars.h"

class Circuit {
	std::vector<Car*> Racers;
	std::vector<Car*> Finished;
	std::vector<Car*> NotFinished;
	unsigned int lengthOfCircuit;
	Weather w;
public:
	Circuit();
	void AddCar(Car* c);
	void Race();
	void SetLength(unsigned int len);
	void SetWeather(Weather _w);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};
