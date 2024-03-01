#include <iostream>
using namespace std;

long long int squarerootInt(int n)
{
    long long int s = 0, e = n, mid = s + (e - s) / 2;
    long long int ans = -1;

    while (s <= e)

    {
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        if (square > n)
        {
            e = mid - 1;
        }
        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempsol)
{
    double factor = 1;
    double ans = tempsol;
    for (double i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    int tempsol = squarerootInt(n);
    double final_ans = morePrecision(n, 10, tempsol);
    cout << "The square root of " << n << " is " << final_ans << endl;
    return 0;
}