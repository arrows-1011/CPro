#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll mod_pow(ll x, ll n, ll mod)
{
    if (n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    
    bool ok = 1;
    if (N % 2 && cnt[0] != 1) ok = 0;
    for (int i = N - 1; i > 0; i -= 2) {
        if (cnt[i] != 2) {
            ok = 0;
            break;
        }
    }

    if (ok) {
        cout << mod_pow(2, N / 2, (1e9) + 7) << endl;
    } else {
        cout << 0 << endl;
    }   
    return 0;
}
