#include <bits/stdc++.h>

using namespace std;

#define COCOA 100000

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i]; v[i]--;
    }
    int cnt[COCOA] = {};
    int l = 0, res = 0;
    for (int r = 0; r < N; r++) {
        cnt[v[r]]++;
        while (cnt[v[r]] > 1) {
            cnt[v[l]]--;
            l++;
        }
        
        res = max(res, r - l + 1);
    }
    cout << res << endl;
    return 0;
}
