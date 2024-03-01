#include <iostream>
using namespace std;
void reverse(string &str, int s, int e)
{
    cout << "Call received for " << str << endl;
    if (s > e)
        return;
    swap(str[s], str[e]);
    s++;
    e--;
    reverse(str, s, e);
}
int main()
{
    string str = "abcdefghijklm";
    reverse(str, 0, str.length() - 1);
    cout << endl;
    cout << "After calling fun reverse :" << str << endl;
    cout << endl;

    return 0;
}