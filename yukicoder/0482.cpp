#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    ll N, K;    
    cin >> N >> K;
    vector<int> D(N), p(N);
    for (ll i = 0; i < N; i++) {
        cin >> D[i];
        D[i] -= 1;
        p[D[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        if (D[i] == i) continue;
        int d = D[i];
        swap(D[i], D[p[i]]);
        swap(p[i], p[d]);
        K -= 1LL;
    }

    if (K < 0LL) {
        cout << "NO" << endl;
    } else {
        cout << (K % 2LL == 0LL ? "YES" : "NO") << endl;
    }    
    return 0;
}
