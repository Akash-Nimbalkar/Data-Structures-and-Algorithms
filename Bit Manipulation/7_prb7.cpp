/* You have a 32-bit unsigned integer called 'num' and another integer called 'i'.
You need to perform the following operations on the 'num' integer based on the value of 'i':
1. Get the bit value at the "i"th position of "num".
2. Set the bit at the "i"th position of "num".
3. Clear the bit at the "i"th position of "num".
We are starting bits from 1 instead of 0. (1-based)

For Example:
N=25  i=3
Output : 0 29 25
Bit at the 3rd position from LSB is 0. (1 1 0 0 1)
The value of the given number after setting the 3rd bit is 29. (1 1 1 0 1)
The value of the given number after clearing the 3rd bit is 25. (1 1 0 0 1) */
#include <bits/stdc++.h>
using namespace std;

vector<int> bitManipulation(int num, int i)
{
    vector<int> ans;

    int mask = 1 << i - 1;

    if ((num & mask) == 0)
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(1);
    }

    num = num | mask;
    ans.push_back(num);

    num = num ^ mask;
    ans.push_back(num);

    return ans;
}

int main()
{
    int num;
    cin >> num;

    vector<int> ans = bitManipulation(num, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}