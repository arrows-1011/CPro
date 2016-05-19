#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int mx = 0, r = 0, res = 0;
    for (int l = 0; l < N; ) {
        while (r < N && mx < a[r]) {
            mx = a[r];
            r++;
        }
        res += max(0, r - l + 1 - K);
        mx = a[r];
        l = r; r++;
    }
    cout << res << endl;
    return 0;
}
