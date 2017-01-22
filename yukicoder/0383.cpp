#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    b -= a;
    if (b > 0) {
        cout << "+" << b << endl;
    } else {
        cout << b << endl;
    }        
    return 0;
}
