#include <iostream>

using namespace std;

int main()
{
    int a, b;
    char op;
    cin >> a >> op >> b;
    cout << (op == '+' ? a + b : a - b) << endl;
    return 0;
}
