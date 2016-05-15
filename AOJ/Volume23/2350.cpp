#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> Vec;

ll solve(Vec &a, Vec &b, ll idx, ll k, ll c)
{
    if (idx == (int)a.size()) return 0;
        
    ll res = 0;
    ll A = a[idx], B = b[idx];
    if (A - c >= B) {
        ll C = (A - c - B) * pow(10, idx);
        res = solve(a, b, idx + 1, k, 0) + C;
    } else {
        ll C = (A - c + 10 - B) * pow(10, idx);
        res = solve(a, b, idx + 1, k, 1) + C;        
        if (k > 0) {
            res = max(res, solve(a, b, idx + 1, k-1, 0) + C);
        }
    }
    return res;
}

int main()
{
    string A, B;
    ll K;
    cin >> A >> B >> K;
    vector<ll> a, b; 
    for (ll i = (ll)A.size()-1; i >= 0; i--) {
        a.push_back(A[i]-'0');
    }

    for (ll i = (ll)B.size()-1; i >= 0; i--) {
        b.push_back(B[i]-'0');
    }

    while (b.size() != a.size()) b.push_back(0);
    
    cout << solve(a, b, 0, K, 0) << endl;
    return 0;
}
