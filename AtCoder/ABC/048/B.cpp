#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll res = b / x - (a == 0 ? -1 : (a - 1) / x);
    cout << res << endl;
    return 0;
}
