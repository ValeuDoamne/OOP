#include "Sort.h"
#include <cstring>
#include <cstdarg>
#include <cstdlib>
#include <iostream>
using namespace std;

Sort::Sort(int n, int min, int max)
{
	srand(time(0));
	count = 0;
	while(count < n)
	{
		int x = rand()%max;
		if(x > min)
			A[count++] = x;
	}
}

Sort::Sort(initializer_list<int> list)
{
    count = 0;
    for (int x : list) {
        A[count] = x;
        count++;
    }
}

Sort::Sort(int v[], int n)
{
	for(int i = 0; i < n; i++)
		A[i] = v[i];
}

Sort::Sort(int n, ...)
{
	va_list l;
	va_start(l, n);
	for(int i = 0; i < n; i++)
	{
		int val = va_arg(l, int);
		A[i] = val;
	}
	va_end(l);
	count = n;
}

Sort::Sort(const char* lista)
{
	char s[512];
	strcpy(s, lista);
	char *p = strtok(s, " ,");
	count = 0;
	while(p != NULL)
	{
		int x = atoi(p);
		A[count++] = x;
		p = strtok(NULL, " ,");
	}
}

void Sort::InsertSort(bool ascendent)
{
	if(ascendent){
		int i, key, j;
		for (i = 1; i < count; i++)
		{
			key = A[i];
			j = i - 1;

			while (j >= 0 && A[j] > key)
			{
				A[j + 1] = A[j];
				j = j - 1;
			}
			A[j + 1] = key;
		}	
	} else {
		int i, key, j;
		for (i = 1; i < count; i++)
		{
			key = A[i];
			j = i - 1;

			while (j >= 0 && A[j] < key)
			{
				A[j + 1] = A[j];
				j = j - 1;
			}
			A[j + 1] = key;
		}	
	}
}

void quicksort(int v[], int st,int dr)
{
	if(st < dr)
	{
		int m = (st+dr)/2;
		int i = st, j = dr, d = 0;
		swap(v[st], v[m]);

		while(i < j)
		{
			if(v[i] > v[j])
			{
				swap(v[i], v[j]);
				d =1-d;
			}
			i+=d;
			j-=1-d;
		}
		quicksort(v, st, i-1);
		quicksort(v, i+1, dr);
	}
}

void Sort::QuickSort(bool ascendent)
{

	if(ascendent)
		quicksort(A, 0, count);
	else {
	
		quicksort(A, 0, count);
		for(int i = 0; i < count/2; i++)
			swap(A[i], A[count-i]);
	}
}

void Sort::BubbleSort(bool ascendent)
{
	if(ascendent)
	{
		for(int i = 0; i < count; i++)
			for(int j = 0; j < count; j++)
				if(A[i] > A[j])
					swap(A[i], A[j]);
	} else {
		for(int i = 0; i < count; i++)
			for(int j = 0; j < count; j++)
				if(A[i] < A[j])
					swap(A[i], A[j]);

	} 
}

void Sort::Print()
{
    for (int i = 0; i < count; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int Sort::GetElementsCount() const
{
    return count;
}

int Sort::GetElementFromIndex(int index) const
{
	if(index < 0 || index >= count)
		return -1;
	return A[index];
}
