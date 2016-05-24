#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
#define INF (1LL<<55)
typedef long long ll;

int main()
{
    int N, M, l, r, s;
    ll sum = 0;
    cin >> N >> M;
    ll imos[MAX] = {};
    for (int i = 0; i < N; i++) {
        cin >> l >> r >> s;
        l--; r--;
        imos[l] += s;
        imos[r+1] -= s;
        sum += s;
    }

    for (int i = 1; i < MAX; i++) {
        imos[i] += imos[i-1];
    }

    ll res = 0;
    for (int i = 0; i < M; i++) {
        res = max(res, sum - imos[i]);
    }
    cout << res << endl;
    return 0;
}
