#include <iostream>
using namespace std;

char maxoccurchar(string str)
{
    int arr[26] = {0}; // Initialize array with 0
    int num;
    // Create an array of count of characters
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            num = str[i] - 'a';
        }
        else
        {
            num = str[i] - 'A';
        }
        arr[num]++;
    }

    int maxi = -1, max_index = -1;
    // Find out max occured character
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxi)
        {
            max_index = i;
            maxi = arr[i];
        }
    }
    return max_index + 'a';
}
int main()
{
    string s;
    cout << "Enter your input string" << endl;
    cin >> s;
    cout << "Maximum occuring character in the string " << s << " is " << maxoccurchar(s) << endl;

    return 0;
}