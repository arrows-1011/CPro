#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    int N;
    cin >> N;
    ll t = 1, a = 1;
    for (int i = 0; i < N; i++) {
        ll T, A;
        cin >> T >> A;
        ll x = max(t / T + (t % T > 0), a / A + (a % A > 0));        
        t = x * T;
        a = x * A;
    }
    cout << t + a << endl;
    return 0;
}
