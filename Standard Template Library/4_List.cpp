#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(2);
    l.push_front(4);
    l.push_front(6);

    for (int i : l)
    {
        cout << i << " ";
    }
    l.erase(l.begin());
    cout << "After erase " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    return 0;
}