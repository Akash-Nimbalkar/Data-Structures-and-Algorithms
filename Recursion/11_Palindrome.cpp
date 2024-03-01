#include <iostream>
using namespace std;
bool isPalindrome(string s, int i, int j)
{
    if (i > j) // base case
        return true;

    if (s[i] != s[j])
        return false;
    else
    {
        return isPalindrome(s, i + 1, j - 1); // recursive call
    }
}
int main()
{
    string s = "bookkboob";
    cout << isPalindrome(s, 0, s.length() - 1);

    return 0;
}