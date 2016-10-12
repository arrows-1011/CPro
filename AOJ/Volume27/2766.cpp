#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, D;
    string X;
    cin >> N >> X >> D;
    vector<bool> used(N);
    for (int i = 0; D > 0 && i < N; i++) {
        if (X[i] == '0') {
            used[i] = 1;
            X[i] = '1';
            D--;
        }
    }
    
    for (int i = N - 1; D > 0 && i >= 0; i--) {
        if (X[i] == '1' && !used[i]) {
            X[i] = '0';
            D--;
        }
    }
    
    cout << X << endl;
    return 0;
}
