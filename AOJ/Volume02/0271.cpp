#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define MOD 1000000007
typedef long long ll;

int bit[MAX], N;

int sum(int i)
{
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x)
{
    while (i <= N) {
        bit[i] += x;
        i += i & -i;
    }
}

int main()
{
    ll fact[MAX];    
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = ((ll)i * fact[i-1]) % MOD;
    }
    
    int R, s, t;
    while (cin >> N, N) {
        cin >> R;
        vector<ll> v(N);
        for (int i = 0; i < N; i++) {
            v[i] = i + 1;
        }
        for (int i = 0; i < R; i++) {
            cin >> s >> t;
            s--; t--;
            swap(v[s], v[t]);
        }

        memset(bit, 0, sizeof(bit));
        
        ll res = 0;
        for (int i = N-1; i >= 0; i--) {
            add(v[i], 1);
            res += fact[(N - i - 1)] * sum(v[i]-1);
            res %= MOD;
        }
        cout << res << endl;
    }       
    return 0;
}
