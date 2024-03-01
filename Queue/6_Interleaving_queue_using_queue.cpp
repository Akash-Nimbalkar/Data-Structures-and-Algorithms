// Interleave the first half of the queue with second half using queue
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

    queue<int> temp;
    int n = q.size();

    for (int i = 0; i < n / 2; i++)
    {
        temp.push(q.front());
        q.pop();
    }

    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}