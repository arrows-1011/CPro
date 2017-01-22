#include <iostream>

using namespace std;

int main()
{
    using ll = long long;
    
    ll N, M;
    cin >> N >> M;

    if (M * 1000 > N) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << N / 1000 / M * 1000 << endl;
    return 0;
}
