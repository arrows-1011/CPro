#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll H, W, N, K;
    cin >> H >> W >> N >> K;
    cout << ((H * W - 1) % N + 1 == K ? "YES" : "NO") << endl;
    return 0;
}
