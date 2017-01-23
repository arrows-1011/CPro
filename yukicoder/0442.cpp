#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
    ll A, B;
    cin >> A >> B;
    ll g = __gcd(A, B);
    cout << g * __gcd(A / g + B / g, g) << endl;
    return 0;
}
