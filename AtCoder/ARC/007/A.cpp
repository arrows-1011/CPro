#include <bits/stdc++.h>

using namespace std;

int main()
{
    char X;
    string s;
    cin >> X >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == X) continue;
        cout << s[i];
    }
    cout << endl;
    return 0;
}
