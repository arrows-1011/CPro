#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, N;
    cin >> m >> n >> N;
    
    int cnt = N, rem = 0;
    while (N >= m) {
        cnt += N/m * n;
        rem += N % m;
        N = N / m * n;
        if (N < m) {
            N += rem;
            rem = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
