
#include "stdafx.h"
#include <iostream>
using namespace std;

// Функция изменяет аргументы: первый по ссылке, второй по указателю
void modifyValues(int& refArg, int* ptrArg)
{
    refArg = refArg * 2;      // изменяем через ссылку
    *ptrArg = *ptrArg * 3;    // изменяем через указатель
}

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "Russian");

    // ИСПРАВЛЕНО: создаём обычные переменные
    int x_val, y_val, z_val, d;

    // ИСПРАВЛЕНО: указатели инициализируем адресами переменных
    int* x = &x_val, * y = &y_val, * z = &z_val;

    cout << "Введите 3 числа:" << endl;
    cin >> *x >> *y >> *z;

    //  ИСПРАВЛЕНО: сравниваем значения (*x, *y, *z), а не адреса
    if (*x > *y)
    {
        d = *x; *x = *y; *y = d;
    }
    if (*x > *z)
    {
        d = *z; *z = *x; *x = d;
    }
    if (*y > *z)
    {
        d = *y; *y = *z; *z = d;
    }

    cout << "x=" << *x << " y=" << *y << " z=" << *z;
    cout << " difference = " << *z - *x << endl;

    // Демонстрация работы ссылок и указателей
    int a = 5, b = 10;
    cout << "\nДо: a=" << a << ", b=" << b << endl;
    modifyValues(a, &b);
    cout << "После: a=" << a << ", b=" << b << endl;

    return 0;
}