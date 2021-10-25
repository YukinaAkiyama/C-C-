#include <iostream>
using namespace std;
#include <string>

template <typename T>
 T Max(T a, T b)
{
    return a > b ? a : b;
}
 template <typename T>
 T Min(T a, T b)
{
     return a < b ? a : b;
}
int main()
{
    int x = 39;
    int y = 20;
    cout << "Max(x, y): " << Max(x, y) << endl;
    cout << "Min(x, y): " << Min(x, y) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;
    cout << "Min(f1, f2): " << Min(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
    cout << "Min(s1, s2): " << Min(s1, s2) << endl;

    string b1 = "[]\|;,";
    string b2 = "()-=;;>";
    cout << "Max(b1,b2): " << Max(b1,b2) << endl;
    cout << "Min(b1,b2): " << Min(b1,b2) << endl;

    return 0;
}