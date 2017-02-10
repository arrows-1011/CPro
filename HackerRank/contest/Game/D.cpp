#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, x, res = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x;
            res ^= x;
        }
        cout << (res > 0 ? "First" : "Second") << endl;
    }
    return 0;
}
