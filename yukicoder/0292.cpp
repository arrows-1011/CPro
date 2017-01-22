#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int t, u;
    bool rem[50];
    fill(rem, rem + 50, 1);
    
    cin >> s >> t >> u;
    rem[t] = rem[u] = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (rem[i]) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
