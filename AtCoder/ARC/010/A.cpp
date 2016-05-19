#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<int> c(M);
    for (int i = 0; i < M; i++) {
        cin >> c[i];
    }
    
    bool ok = 1;
    for (int i = 0; i < M; i++) {
        if (N <= A) N += B;

        N -= c[i];
        if (N < 0) {
            ok = 0;
            cout << i+1 << endl;
            break;
        }
    }
    if (ok) cout << "complete" << endl;
    return 0;
}
