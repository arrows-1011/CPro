#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
constexpr int MAX = 2010;

int N, M, L;
ll memo[MAX][MAX];
vector<ll> K, sum;

ll calc(int l, int r)
{
    return (sum[K[r] + 1] - sum[K[l]]) / L;
}

ll solve(int l, int r)
{    
    ll& res = memo[l][r];
    if (res != -1) return res;

    int n = max(l, r) + 1;
    if (n == N - 1) {
        return calc(l, n) + calc(r, n);
    }
    res = min(solve(n, r) + calc(l, n),
              solve(l, n) + calc(r, n));    
    return res;
}

int main()
{    
    cin >> N >> M >> L;
    K.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> K[i]; K[i]--;
    }
    sort(K.begin(), K.end());
    
    vector<int> S(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
    }
    
    sum.resize(M + 1);
    for (int i = 0; i < M; i++) {
        sum[i + 1] = sum[i] + S[i];
    }
    
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0) << endl;
    return 0;
}
