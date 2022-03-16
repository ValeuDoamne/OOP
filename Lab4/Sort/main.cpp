#include "Sort.h"

int main() {
    Sort s1(10, 100, 200);
    Sort s2({ 1, 2, 3, 4, 5, 6 });
    s2.Print();

    int v[3]; v[0] = 10; v[1] = 20; v[2] = 30;
    Sort s3(v, 3);

    Sort s4(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    s4.Print();
    Sort s5("10,40,100,5,70");

    s5.Print();
    s5.QuickSort(false);
    s5.Print();
    return 0;
}
