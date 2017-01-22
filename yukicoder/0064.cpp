#include <iostream>

using namespace std;

int main()
{
    using ll = long long;
    ll F[3], N;
    cin >> F[0] >> F[1] >> N;
    F[2] = F[0] ^ F[1];
    cout << F[N % 3] << endl;
    return 0;
}
