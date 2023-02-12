// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double funkcja(double x)
{
    return cos(x) + atan(x);
}

double funkcja_poch(double x)
{
    return -sin(x) + 1. / (1 + x * x);
}

double bisekcja(double a, double b, double eps)
{
    int number = 0;
    double mid;
    while (abs(b - a) > eps)
    {
        mid = (a + b) / 2;
        if (funkcja(mid) * funkcja(a) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
        number++;
    }
    
    cout << "Liczba wykonanych operacji: " << number << endl;
    return mid;
}

double sieczne(double a, double b, double eps)
{
    int number = 0;
    double mid;
    while (abs(b - a) > eps)
    {
        mid = (a * funkcja(b) - b * funkcja(a)) / (funkcja(b) - funkcja(a));
        if (funkcja(mid) * funkcja(a) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
        number++;
    }
    cout << "Liczba wykonanych operacji: " << number << endl;
    return mid;
}

double Newton(double a, double eps)
{
    int number = 0;
    double mid;
    while (abs(funkcja(a)) > eps)
    {
        mid = a - funkcja(a) / funkcja_poch(a);
        a = mid;
        number++;
    }
    cout << "Liczba wykonanych operacji: " << number << endl;
    return a;
}

int main()
{
    double a = -2.5;
    double b = 3;
    double eps = 0.00000000000001;
    cout << "Uzyte wartosci wynosza\na = " << a << "\nb = " << b << "\nepsilon = " << eps << endl;
    cout << "\nMetoda bisekcji\n";
    double m0b;
    m0b = bisekcja(a, b, eps);
    cout.precision(14);
    cout << "Obliczone miejsce zerowe: " << m0b << endl;

    cout << "Metoda siecznych\n";
    double m0s;
    m0s = sieczne(a, b, eps);
    cout << "Obliczone miejsce zerowe: " << m0s << endl;

    cout << "Metoda Newtona\n";
    double m0n;
    m0n = Newton(a, eps);
    cout << "Obliczone miejsce zerowe: " << m0n << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
