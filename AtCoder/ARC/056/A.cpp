#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll A, B, K, L;
    cin >> A >> B >> K >> L;
    ll rem = K - (K / L) * L;
    cout << B * (K / L) + min(A * rem, B) << endl;
    return 0;
}
