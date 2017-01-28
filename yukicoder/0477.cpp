#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    cout << N / (K + 1) + 1 << endl;
    return 0;
}
