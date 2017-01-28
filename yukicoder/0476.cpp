#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll n, a, s = 0;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s += x;        
    }

    cout << (n * a == s ? "YES" : "NO") << endl;
    return 0;
}
