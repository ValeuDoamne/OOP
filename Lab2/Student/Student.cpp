#include "Student.h"
#include <string>

std::string Student::GetName() const
{
	return this->name;
}

void Student::SetName(std::string newName)
{
	this->name = newName;
}

float Student::GetGradeHistory() const
{
	return history;
}

float Student::GetGradeEnglish() const
{
	return english;
}

float Student::GetGradeMathematics() const
{
	return math;
}


void Student::SetGradeEnglish(float grade)
{
	if(grade < 0 || grade > 10)
		return;
	english = grade;
}


void Student::SetGradeMathematics(float grade)
{
	if(grade < 0 || grade > 10)
		return;
	math = grade;
}


void Student::SetGradeHistory(float grade)
{
	if(grade < 0 || grade > 10)
		return;
	english = grade;
}

float Student::Average() const
{
	return (math + english + history) / 3.;
}
