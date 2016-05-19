#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char a = s[i];
        if (a == 'O' || a == 'D') {
            cout << 0;
        } else if (a == 'I') {
            cout << 1;
        } else if (a == 'Z') {
            cout << 2;
        } else if (a == 'S') {
            cout << 5;
        } else if (a == 'B') {
            cout << 8;
        } else {
            cout << a;
        }
    }
    cout << endl;
    return 0;
}
