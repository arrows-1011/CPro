#include <iostream>

using namespace std;

using ll = long long;
constexpr ll MOD = ((1e9) + 7);

int main()
{
    int N;
    ll res = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll C, D;
        cin >> C >> D;        
        res = (res + (((C + 1) / 2)  % MOD * (D % MOD))) % MOD;
    }
    cout << res << endl;
    return 0;
}
