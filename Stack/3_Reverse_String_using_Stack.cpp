#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> st;
    string str = "ANIKET";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }
    string ans = "";
    while (!st.empty())
    {
        char c = st.top();
        ans.push_back(c);
        st.pop();
    }
    cout << ans << endl;

    return 0;
}