#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    constexpr int INF = (1 << 29);
    int N = s.size(), res = INF;    
    for (int i = 0; i < N; i++) {
        if (s[i] != 'w') continue;
        int l = i - 1, r = i + 1;
        while (l >= 0 && s[l] != 'c') l--;
        while (r < N && s[r] != 'w') r++;
        if (l >= 0 && r < N) {
            res = min(res, r - l + 1);
        }
    }
    if (res == INF) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }        
    return 0;
}
