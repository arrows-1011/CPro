#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (A < B) {
        cout << A - 1 + B - A - 1 << endl;
    } else {
        cout << 2000000000 - A + A - B - 1 << endl;
    }        
    return 0;
}
