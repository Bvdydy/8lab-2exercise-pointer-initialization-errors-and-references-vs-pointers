// exercise2_buggy.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    int* x, * y, * z, d;

    cout << "3 number, please" << endl;
    cin >> *x >> *y >> *z;  // ОШИБКА: указатели не инициализированы!

    if (x > y)  // ОШИБКА: сравниваем адреса, а не значения
    {
        d = *x; x = y; *y = d;
    }
    if (x > z)
    {
        d = *z; z = x; *x = d;
    }
    if (y > z)
    {
        d = *y; y = z; *z = d;
    }

    cout << "x=" << x << " y=" << y << " z=" << z << endl;

    return 0;
}