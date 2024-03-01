// 1.Find length 2.reverse a string 3. check palindrome or not

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
int getLength(char str[])
{

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse_string(char str[], int n)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
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
            s++;
            e--;
        }
    }
    return 1;
}
int main()
{
    char str[30];

    cout << "Enter your string" << endl;
    cin >> str;
    int n = getLength(str);

    cout << "Given string " << str << " is of length " << getLength(str) << endl;

    reverse_string(str, n);
    cout << "Reverse of given string is " << str << endl;

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