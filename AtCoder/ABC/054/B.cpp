#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<string> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    bool found = 0;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            bool ok = 1;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A[i + k][j + l] != B[k][l]) {
                        ok = 0;
                    }
                }
            }
            found |= ok;
        }
    }
    cout << (found ? "Yes" : "No") << endl;
    return 0;
}
