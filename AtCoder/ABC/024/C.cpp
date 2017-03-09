#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, D, K;
    cin >> N >> D >> K;
    
    vector<int> L(D), R(D);
    for (int i = 0; i < D; i++) {
        cin >> L[i] >> R[i];
    }

    vector<int> S(K), T(K);
    for (int i = 0; i < K; i++) {
        cin >> S[i] >> T[i];
    }
        
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < D; j++) {
            if (L[j] <= S[i] && S[i] <= R[j]) {
                if (S[i] > T[i]) {
                    S[i] = max(L[j], T[i]);
                } else {
                    S[i] = min(R[j], T[i]);
                }
            }

            if (S[i] == T[i]) {
                cout << j + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
