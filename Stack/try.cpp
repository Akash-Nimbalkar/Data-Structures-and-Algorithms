#include <iostream>
using namespace std;
int convertFive(int n)
{
    int sum = 0;
    while (n != 0)
    {

        int rem = n % 10;
        if (rem == 0)
        {
            rem = 5;
        }
        sum = sum + rem * 10;
        n = n / 10;
    }
}
int main()
{
    int n = 1020;
    cout << convertFive(n) << endl;

    return 0;
}