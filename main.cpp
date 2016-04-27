#include <iostream>
#include "allocator.h"

using namespace std;

int main()
{
    Allocator<int> test;
    int* a = test.allocate(1);
    a[1] = 1;
    for (int i = 0; i < 6; i++) cout << (a[i]) << endl;
    cout << endl;
    test.deallocate(a, 4);
    a[0] = 2;
    for (int i = 0; i < 6; i++) cout << (a[i]) << endl;
    return 0;
}