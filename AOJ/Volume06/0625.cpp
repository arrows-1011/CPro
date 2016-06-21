#include <bits/stdc++.h>

using namespace std;

#define MAX 25252
#define INF (1LL<<55)
typedef long long ll;

ll N, M, K;
ll memo[MAX];
vector<ll> A;

ll solve(int n)
{
    if (n == N) return 0;
    ll &res = memo[n];

    if (res != -1) return res;
    res = INF;
    
    ll maxi = 0, mini = INF;
    for (int i = n; i < min(n + M, N); i++) {
        maxi = max(maxi, A[i]);
        mini = min(mini, A[i]);
        ll cost = K + (i+1 - n) * (maxi - mini);
        res = min(res, solve(i+1) + cost);
    }
    return res;
}

int main()
{
    cin >> N >> M >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << solve(0) << endl;
    return 0;
}
