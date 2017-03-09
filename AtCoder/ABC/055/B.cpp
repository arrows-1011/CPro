#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = ((1e9) + 7);

int main()
{
    ll N, p = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        p *= (i + 1);
        p %= MOD;
    }
    cout << p << endl;
    return 0;
}
