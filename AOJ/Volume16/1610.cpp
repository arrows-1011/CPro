#include <bits/stdc++.h>

using namespace std;

constexpr int LIMIT = 7368791;

bool used[LIMIT+1];

int main()
{
    int m, n;
    while (cin >> m >> n, m) {
        int cnt = 0;
        memset(used, 0, sizeof(used));
        for (int i = m; cnt < n; i++) {
            if (!used[i]) {
                cnt++;
                for (int j = i; j <= LIMIT; j += i) {
                    used[j] = 1;
                }
            }
        }
        for (int i = m; ; i++) {
            if (!used[i]) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
