#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("Akash");
    s.push("Yashwant");
    s.push("Nimbalkar");
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "Size of stack is " << s.size() << endl;
    cout << "Empty or not " << s.empty() << endl;

    return 0;
}