#include <bits/stdc++.h>

using namespace std;

int main()
{
    int E[6], B, L[6];
    for (int i = 0; i < 6; i++) {
        cin >> E[i];
    }
    cin >> B;
    for (int i = 0; i < 6; i++) {
        cin >> L[i];
    }
    
    int N = 6;
    do {
        bool use_b = 0;
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (L[i] == E[i]) {
                ++cnt;
            }
            if (L[i] == B) {
                use_b = 1;
            }
        }
        if (cnt >= 3) {
            if (cnt == 6) {
                N = min(N, 1);
            } else if (cnt == 5) {
                N = min(N, 3 - use_b);
            } else if (cnt == 4) {
                N = min(N, 4);
            } else if (cnt == 3) {
                N = min(N, 5);
            }
        }
    } while (next_permutation(E, E + 6));
    cout << (N % 6) << endl;        
    return 0;
}
