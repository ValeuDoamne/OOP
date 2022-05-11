#include "Map.h"
#include <iostream>

int main()
{
    Map<int, const char *> m;
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    m[10] = "C++";
    m[20] = "test";
    m[30] = "POO";
    for (auto[key, value, index] : m)
    {
        printf("Index=%d, Key=%d, Value=%s\n", index, key, value);

    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index=%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;

}
