#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
constexpr int MAX = 10;

bool con[MAX][MAX]; /* con[i][j] = 1 -> connect */

inline int mod_pow(ll x, int n, int mod)
{
    if (n == 0) return 1;
    int res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}

int I[1 << MAX], bn[1 << MAX];

bool c(int n, int k)
{
    ll g = 0;
    constexpr int MOD = 10009;    
    for (int i = 0; i < (1 << n); i++) {
        if (bn[i] % 2 == 0) {
            g += mod_pow(I[i], k, MOD);
        } else {
            g -= mod_pow(I[i], k, MOD);
        }
    }
    return (g % MOD + MOD) % MOD != 0;
}

int paint_color_number(int n)
{
    vector<int> N(1 << n);
    for (int i = 0; i < n; i++) {
        int bit = (1 << i);
        for (int j = 0; j < n; j++) {
            if (con[i][j]) {
                bit |= (1 << j);
            }
        }
        N[i] = bit;
    }
        
    memset(I, 0, sizeof(I));
    I[0] = 1;
    for (int S = 1; S < (1 << n); S++) {
        bn[S] = __builtin_popcount(S);
        int v = 0;
        while (!(S >> v & 1)) v++;
        I[S] = I[S - (1 << v)] + I[S & ~N[v]];
    }
            
    int L = 0, R = n;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (c(n, mid)) {
            R = mid;
        } else {
            L = mid;
        }           
    }
    return R;
}
