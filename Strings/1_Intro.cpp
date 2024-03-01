#include <iostream>
using namespace std;

int main()
{
    // char name[20];
    // cout << "Enter your name " << endl;
    // cin >> name;
    // name[3] = '\0';
    // cout << "Welcome " << name << endl;
    char str[20];
    cout << "Enter any string " << endl;
    cin.getline(str, 20);
    cout << "Your input string : " << str << endl;
    return 0;
}