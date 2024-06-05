#include "head.h"
#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int b = 2;

    cout << "a + b = " << add(a,b) << endl;
    cout << "a - b = " << subtract(a,b) << endl;
    cout << "a * b = " << multiply(a,b) << endl;
    cout << "a / b = " << divide(a,b) << endl;
    return 0;
}