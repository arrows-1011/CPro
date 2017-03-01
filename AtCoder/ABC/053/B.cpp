#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int N = s.size();
    int l = 0, r = N - 1;
    while (l < N && s[l] != 'A') {
        l += 1;
    }

    while (r >= 0 && s[r] != 'Z') {
        r -= 1;
    }
    
    cout << max(0, r - l + 1) << endl;
    return 0;
}
