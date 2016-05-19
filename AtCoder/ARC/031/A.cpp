#include <bits/stdc++.h>

using namespace std;

bool check(string &s)
{
    for (int i = 0; i < (int)s.size()/2; i++) {
        if (s[i] != s[s.size()-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string name;
    cin >> name;
    cout << (check(name) ? "YES" : "NO") << endl;
    return 0;
}
