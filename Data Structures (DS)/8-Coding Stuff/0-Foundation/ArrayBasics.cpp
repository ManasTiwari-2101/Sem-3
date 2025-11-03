#include <iostream>
using namespace std;

int main()
{
    int A[5] = {2, 4, 6, 8, 10};

    // Normal For Loop
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }

    // Range-based For Loop (C++11 and later)
    for (int x : A)
    {
        cout << x << endl;
    }

    return 0;
}