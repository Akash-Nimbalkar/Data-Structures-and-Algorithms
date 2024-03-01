#include <iostream>
#include <vector>
using namespace std;

int main()
{ // Vector initialisation
    vector<int> v;
    vector<int> a(5, 1); // 5 indicates the size of vector and all places will be initialised with 1 ONLY.

    for (int i : a)
    {
        cout << i << " ";
    }

    // copying a vector
    vector<int> last(a);
    for (int i : last)
    {
        cout << i << " ";
    }
    // Capacity & Size
    cout << "Capacity " << v.capacity() << endl;
    v.push_back(11);

    cout << "Capacity " << v.capacity() << endl;
    v.push_back(22);

    cout << "Capacity " << v.capacity() << endl;
    v.push_back(33);
    cout << "Capacity " << v.capacity() << endl;
    cout << "Size " << v.size() << endl;

    // Element location
    cout << "Element at second index is " << v.at(2) << endl;
    cout << "First Element " << v.front() << endl;
    cout << "Last Element " << v.back() << endl;

    cout << "Before pop: " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "After pop: " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Before clear Size " << v.size() << endl;
    v.clear();
    cout << "After clear Size " << v.size() << endl;

    return 0;
}