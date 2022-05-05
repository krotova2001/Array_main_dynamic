#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array<int> A;
    A.Add(7);
    A.Add(8);
    A.Show();
    A.SetSize(5,2);
    A.Show();
}
