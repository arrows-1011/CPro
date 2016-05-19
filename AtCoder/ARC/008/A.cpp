#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, res = 114514;
    cin >> N;
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            if (i + 10*j < N) continue;
            res = min(res, 15*i + 100*j);
        }
    }
    cout << res << endl;
    return 0;
}
