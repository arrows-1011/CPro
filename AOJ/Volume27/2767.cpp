#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    
    vector<int> cnt(26);
    for (int i = 0; i < N; i += 2) {
        cnt[S[i] - 'a'] += 1;
    }
    
    vector<int> p(10);
    for (int i = 0; i < 26; i++) {
        p[cnt[i]] += 1;
    }

    int res = 2 * p[1];
    for (int i = 2; i <= 9; i++) {
        if (p[i] == 1) {
            res += 4;
        } else if (p[i] >= 2) {
            res += 5 + 2 * p[i] - 1;
        }
    }
    cout << res - 1 << endl;    
    return 0;
}

