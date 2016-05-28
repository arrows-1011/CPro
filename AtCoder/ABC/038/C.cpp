#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll dp[MAX] = {0, 1}, n = 2;
    for (int i = 2; i < MAX; i++) {
        dp[i] = dp[i-1] + n;
        n++;
    }

    ll res = 0;
    for (int i = 0; i < N; i++) {
        int v = 0, j = i;
        while (j < N && v < a[j]) {
            v = a[j];
            j++;
        }
        res += dp[j-i];
        i = j-1;
    }
    cout << res << endl;
    return 0;
}
