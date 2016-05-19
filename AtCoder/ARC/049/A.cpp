#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    for (int i = 0; i < 4; i++) {
        int a; cin >> a;
        S.insert(a+i, "\"");
    }
    cout << S << endl;
    return 0;
}
