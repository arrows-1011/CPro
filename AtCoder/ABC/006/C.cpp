#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int main()
{
    int N, M;
    cin >> N >> M;
    bool found = 0;
    for (int x = 0; x < MAX; x++) {
        if (M - 3*N + x >= 0) {
            int z = M - 3*N + x;
            int y = M - 2*N - 2*z;
            if (y >= 0 && z >= 0) {
                cout << x << " " << y << " " << z << endl;
                found = 1;
                break;
            }
        } 
    }
    if (!found) {
        cout << -1 << " " << -1 << " " << -1 << endl;
    }
    return 0;
}
