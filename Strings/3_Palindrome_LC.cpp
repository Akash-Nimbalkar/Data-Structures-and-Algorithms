#include <iostream>
using namespace std;
char toLowercase(int ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else
    {
        ch = ch + 32;
        return ch;
    }
}
bool isPalindrome(char str[], int n)
{
    int s = 0, e = n - 1;

    while (s <= e)
    {
        if (toLowercase(str[s]) != toLowercase(str[e]))
        {
            return 0;
        }
        else
        {
            if ((toLowercase(str[s]) >= 'a' && toLowercase(str[s]) <= 'z') || (toLowercase(str[s]) >= 'A' && toLowercase(str[s]) <= 'Z'))

            {
                s++;
            }
            else
            {
                s = s + 2;
            }
            if ((toLowercase(str[e]) >= 'a' && toLowercase(str[e]) <= 'z') || (toLowercase(str[e]) >= 'A' && toLowercase(str[e]) <= 'z'))
            {
                e--;
            }
            else
            {
                e = e - 2;
            }
        }
    }
    return 1;
}
int main()
{
    char str[30];
    int n;
    cout << "Enter your string & its size" << endl;
    cin >> str >> n;

    if (isPalindrome(str, n))
    {
        cout << "Given string is palindrome" << endl;
    }
    else
    {
        cout << "Given string is not palindrome" << endl;
    }
    return 0;
}