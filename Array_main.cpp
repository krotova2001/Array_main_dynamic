#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array<int> A; //создадим класс и опробуем некоторые опрерации
    A.Add(7);
    A.Add(8);
    A.Show();
    A.SetSize(5,2);
    A.Show();
    //A.FreeExtra();
    cout << "\n";
    cout << A.GetAt(7);
    A.RemoveAt(6);
    A.Show();
}
