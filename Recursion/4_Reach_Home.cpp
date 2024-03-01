#include <iostream>
using namespace std;
void reachedHome(int src, int dest)
{
    if (src == dest)
    {
        cout << "Reached home" << endl;

        return;
    }
    cout << " Source " << src << " Destination " << dest << endl;
    src++;
    reachedHome(src, dest);
}

int main()
{
    reachedHome(1, 10);

    return 0;
}