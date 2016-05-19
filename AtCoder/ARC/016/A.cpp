#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        if (i != M) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
