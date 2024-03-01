#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front of queue is " << q.front() << endl;
    cout << "Size of queue is " << q.size() << endl;

    q.pop();
    cout << "Front of queue is " << q.front() << endl;
    cout << "Size of queue is " << q.size() << endl;

    q.pop();
    q.pop();

    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is not Empty" << endl;
    }
    return 0;
}