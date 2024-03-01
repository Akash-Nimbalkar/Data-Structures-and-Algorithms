#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string" << endl;
    cin >> s;

    // Pre-computation
    int hash[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // Fetch
        cout << c << " appears exactly " << hash[c - 'a'] << " times " << endl;
    }
    return 0;
}