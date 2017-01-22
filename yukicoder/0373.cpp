#include <iostream>

using namespace std;

int main()
{
    using ll = long long;
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (((A * B) % D) * C) % D << endl;
    return 0;
}
