#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll sum = 0LL, res = 0LL;
    for (int i = 0; i < K; i++) {
        sum += a[i];
    }
    res = sum;
    for (int i = K; i < N; i++) {
        sum -= a[i-K];
        sum += a[i];
        res += sum;
    }
    cout << res << endl;
    return 0;
}
