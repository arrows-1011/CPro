#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N, N) {
        vector<int> cnt(26, 0);
        vector<char> ch(N);
        for (int i = 0; i < N; i++) {
            cin >> ch[i];
        }
        
        int mn = -1, mx = 0;
        bool found = 0;        
        for (int i = 0; i < N; i++) {
            int n = ch[i] - 'A';
            cnt[n]++;
            if (mx < cnt[n]) {
                mx = cnt[n];
                mn = n;
            }
                
            int mx2 = 0;
            for (int j = 0; j < 26; j++) {
                if (j == mn) continue;
                mx2 = max(mx2, cnt[j]);
            }
            if (mx2 + (N - i - 1) < mx) {
                found = 1;
                cout << (char)(mn + 'A') << " " << i + 1 << endl;
                break;
            }
        }
        if (!found) {
            cout << "TIE" << endl;
        }
    }
    return 0;
}
