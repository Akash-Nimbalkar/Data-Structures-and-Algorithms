#include <iostream>
using namespace std;
int no_of_steps(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return no_of_steps(n - 1) + no_of_steps(n - 2);
}
int main()
{
    cout << no_of_steps(12) << endl;

    return 0;
}