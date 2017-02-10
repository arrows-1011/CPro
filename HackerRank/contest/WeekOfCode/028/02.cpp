#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

int main()
{
    int Q;
    cin >> Q;
    while (Q--) {
        ll x;
        cin >> x;
        int j = -1;
        for (ll i = 0; i < 50; i++) {
            if (x / (1LL << i) == 0) {
                j = i - 1;
                break;
            }
        }
        
        ll res = !(x >> 0 & 1);
        for (ll i = j; i > 0; i--) {
            if (!(x >> i & 1)) {
                res += pow(2LL, i);
            }
        }
        cout << res << endl;
    }        
    return 0;
}
