#include <iostream>
using namespace std;
string newstr(string &str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
        return temp;
    }
}
int main()
{
    string s;
    cout << "Enter your input string" << endl;
    getline(cin, s);
    cout << s << endl;
    string st = newstr(s);

    for (int i = 0; i < st.length(); i++)
    {
        cout << st[i];
    }
    return 0;
}