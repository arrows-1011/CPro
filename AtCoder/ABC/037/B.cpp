#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N, 0);
    for (int i = 0; i < Q; i++) {
        int L, R, T;
        cin >> L >> R >> T;
        L--; R--;
        for (int j = L; j <= R; j++) {
            v[j] = T;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << v[i] << endl;
    }
    return 0;
}
