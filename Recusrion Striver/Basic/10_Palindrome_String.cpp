#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int i, int n)
{
    if (i >= n / 2)
        return true;

    if (str[i] != str[n - i - 1])
        return false;

    return isPalindrome(str, i + 1, n);
}

int main()
{
    string str;
    cout << "Enter any string" << endl;
    cin >> str;

    if (isPalindrome(str, 0, str.size()))
        cout << str << " is Palindrome!" << endl;
    else
        cout << str << " is not Palindrome!" << endl;
            
    return 0;
}