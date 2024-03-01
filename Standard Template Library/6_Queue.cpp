#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("Akash");
    q.push("Yashwant");
    q.push("Nimbalkar");
    cout << "Front " << q.front() << endl;
    cout << "Size before pop " << q.size() << endl;
    q.pop();
    cout << "Front " << q.front() << endl;
    cout << "Size after pop " << q.size() << endl;

    return 0;
}