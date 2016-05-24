#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N), pos(N+1);
    for (int i = 0; i <= N; i++) {
        if (i < N) a[i] = i + 1;
        pos[i] = (i == 0 ? N : i - 1);
    }
    
    int listen = 0, CD;
    for (int i = 0; i < M; i++) {
        cin >> CD;
        if (CD == listen) continue;
        int next = pos[CD];
        int l = listen;
        swap(a[next], listen);
        swap(pos[l], next);
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
