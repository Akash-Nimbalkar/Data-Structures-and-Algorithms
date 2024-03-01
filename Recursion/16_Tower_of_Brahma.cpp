#include <iostream>
using namespace std;
void Solve(int n, char s, char d, char h)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << s << " to " << d << endl;
        return;
    }
    Solve(n - 1, s, h, d);
    cout << "Move disk " << n << " from " << s << " to " << d << endl;
    Solve(n - 1, h, d, s);
}
int main()
{
    char s = 'A', h = 'B', d = 'C';
    int n;
    cout << "Enter no. of disks " << endl;
    cin >> n;
    Solve(n, s, d, h);
    return 0;
}