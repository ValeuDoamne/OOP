#include "Student.h"

int CompareNames(Student a, Student b)
{
	if(a.GetName() == b.GetName())
		return 0;
	else if(a.GetName() > b.GetName())
		return 1;
	else
		return -1;
}

int CompareAverage(Student a, Student b)
{
	if(a.Average() == b.Average())
		return 0;
	else if(a.Average() > b.Average())
		return 1;
	else
		return -1;
}

int CompareMathematics(Student a, Student b)
{
	if(a.GetGradeMathematics() == b.GetGradeMathematics())
		return 0;
	else if(a.GetGradeMathematics() > b.GetGradeMathematics())
		return 1;
	else
		return -1;
}


int CompareEnglish(Student a, Student b)
{
	if(a.GetGradeEnglish() == b.GetGradeEnglish())
		return 0;
	else if(a.GetGradeEnglish() > b.GetGradeEnglish())
		return 1;
	else
		return -1;
}


int CompareHistory(Student a, Student b)
{
	if(a.GetGradeHistory() == b.GetGradeHistory())
		return 0;
	else if(a.GetGradeHistory() > b.GetGradeHistory())
		return 1;
	else
		return -1;
}
