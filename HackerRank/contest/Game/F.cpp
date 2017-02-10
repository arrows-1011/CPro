#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, res = 0;
        cin >> N;
        vector<int> c(N);
        for (int i = 0; i < N; i++) {
            cin >> c[i];
            if (c[i] & 1) {
                res ^= i;
            }
        }
        cout << (res != 0 ? "First" : "Second") << endl;
    }
    return 0;
}
