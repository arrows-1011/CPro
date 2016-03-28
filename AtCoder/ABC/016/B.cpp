#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C;
    bool a, b;
    cin >> A >> B >> C;
    a = (A + B == C);
    b = (A - B == C);
    if (a && b) {
        cout << "?" << endl;
    } else if (a) {
        cout << "+" << endl;
    } else if (b) {
        cout << "-" << endl;
    } else {
        cout << "!" << endl;
    }
    return 0;
}
