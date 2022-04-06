#include "List.h"

int compare1(int a, int b) {
    if (a < b) return -1;
    if (a == b)return 0;
    return 1;
}

int compare2(int a, int b) {
    if (a < b)return 1;
    if (a == b)return 0;
    return -1;
}

int main() {
    List<int> l;
    l.push(1); l.push(2); l.push(3);
    l.print();
    for (int i = 0; i < 10; ++i) {
        l.push(i);
    }
    l.print();
    l.sort(compare1);

    l.print();
    l.pop();
    l.pop();
    l.pop();
    l.set(3, 1337);
    l.print();
    cout << l.get(1337);

    l.remove(3);
    l.print();
    return 0;
}
