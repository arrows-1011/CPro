#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1024
#define INF LLONG_MAX/4

ll N, W, memo[MAX];
vector<ll> a;

ll solve(int n)
{
    if (n == N) return 0;
    ll &res = memo[n], sum = 0;
    if (res != INF) return res;
    for (int i = n; i < N; i++) {
        sum += a[i];
        res = min(res, solve(i+1) + abs(sum - W));
    }
    res = min(res, solve(N) + max(0LL, sum - W));
    return res;
}

int main()
{
    int T = 1;
    while (cin >> N >> W, N) {
        a.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        fill(memo, memo + MAX, INF);
        cout << "Case " << T++ << ": " << solve(0) << endl;
    }    
    return 0;
}
