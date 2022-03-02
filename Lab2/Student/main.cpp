#include "Student.h"
#include "Helper.h"
#include <iostream>

int main()
{
	Student Alexa;
	Student Grasu;
	Alexa.SetGradeEnglish(9);
	Alexa.SetGradeMathematics(10);
	Alexa.SetGradeHistory(6);
	Alexa.SetName("Alexa Constantin-Cosmin");
	
	Grasu.SetGradeEnglish(10);
	Grasu.SetGradeMathematics(6);
	Grasu.SetGradeHistory(5);
	Grasu.SetName("Grasu Ioan");

	std::cout << CompareAverage(Alexa, Grasu) << std::endl;
}
