#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        a[i]--;
    }
    
    bool used[N];
    memset(used, 0, sizeof(used));
    for (int i = M-1; i >= 0; i--) {
        if (!used[a[i]]) {
            used[a[i]] = 1;
            cout << a[i]+1 << endl;
        }
    }
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            cout << i+1 << endl;
        }
    }
    return 0;
}
