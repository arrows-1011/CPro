#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    int res = 0;
    for (ll i = 0; i <= 62; i++) {
        if (n < (1LL << i)) {
            break;
        }
        ++res;
    }
    cout << res << endl;
    return 0;
}
