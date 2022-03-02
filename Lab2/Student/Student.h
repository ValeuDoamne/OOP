#pragma once
#include <string>


class Student{
	float math, english, history;
	std::string name;
public:
	Student()
	  : math(5), english(5), history(5), name("") // 5 pentru ca e o nota frumoasa
	{ }; 

	std::string GetName() const; 
	void        SetName(std::string newname);

	float GetGradeHistory() const;
	void  SetGradeHistory(float grade);
	
	float GetGradeEnglish() const;
	void SetGradeEnglish(float grade);
	
	float GetGradeMathematics() const;
	void SetGradeMathematics(float grade);
	
	float Average() const;
	
};
