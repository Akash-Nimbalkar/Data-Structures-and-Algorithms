#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    stack<int> st;
    int half = q.size() / 2;
    for (int i = 0; i < half; i++)
    {
        st.push(q.front());
        q.pop();
    }

    for (int i = 0; i < half; i++)
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < half; i++)
    {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < half; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }

    // print
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    return 0;
}