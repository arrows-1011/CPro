#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = n; ; i++) {
        if (i % a == 0 && i % b == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
