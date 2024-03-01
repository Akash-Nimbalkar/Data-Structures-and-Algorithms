#include <iostream>
#include <array>
using namespace std;

int main()
{
    int normal_basic[4] = {1, 2, 3, 4};
    array<int, 4> a = {1, 2, 3, 4};
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "";
    }
    cout << endl;
    cout << "Element at index 3 is " << a.at(3) << endl;
    cout << "Empty or not " << a.empty() << endl;
    cout << "First Element " << a.front() << endl;
    cout << "Last Element " << a.back() << endl;

    return 0;
}