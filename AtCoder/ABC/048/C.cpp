#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }    
    
    ll res = 0;
    for (int i = 1; i < N; i++) {
        if (a[i] + a[i - 1] > x) {
            res += (a[i] + a[i - 1]) - x;
            a[i] = max(0LL, x - a[i - 1]);
        }
    }
    cout << res << endl;
    return 0;
}
