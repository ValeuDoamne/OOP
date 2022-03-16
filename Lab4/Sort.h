#pragma once

#include <initializer_list>
using namespace std;

class Sort
{
    int A[100];
    int count;
public:
    Sort(int n, int min, int max);
    Sort(initializer_list<int> list);
    Sort(int v[], int n);
    Sort(int n, ...);
    Sort(const char* lista);

    void InsertSort(bool ascendent = true);
    void QuickSort(bool ascendent = true);
    void BubbleSort(bool ascendent = true);
    void Print();
    int  GetElementsCount() const;
    int  GetElementFromIndex(int index) const;
};
