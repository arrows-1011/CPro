#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, N, M;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        N %= 2;
        if (N == 0) {
            cout << 2 << endl;
            continue;
        }
        cout << (M != 1 ? 1 : 2) << endl;
    }
    return 0;
}
 
