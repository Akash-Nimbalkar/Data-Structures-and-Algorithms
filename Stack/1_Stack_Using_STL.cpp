#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Creation of stack
    stack<int> s;
    stack<int> s2;

    // Push Operation
    s.push(2);
    s.push(3);
    s.push(5);
    s2.push(10);
    s2.push(20);
    s2.push(30);

    // Pop opeartion
    s.pop();

    // Printing stack top
    cout << "Element at top of stack is " << s.top() << endl;

    if (s.empty())
    {
        cout << "Stack is empty " << endl;
    }
    else
    {
        cout << "Stack is not empty " << endl;
    }
    cout << "The stack has " << s.size() << " elements" << endl;

    // constructs element in-place at the top
    s.emplace(-1);
    cout << "The stack has top element " << s.top() << endl;

    // Swap the contents of stacks with each other
    s.swap(s2);
    cout << "The stack has top element " << s.top() << endl;
    cout << "The stack has top element " << s2.top() << endl;

    return 0;
}