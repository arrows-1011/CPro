#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<bool> used(N + 1);
    vector<int> v(M);
    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }
    
    for (int i = M - 1; i >= 0; i--) {
        if (used[v[i]]) continue;
        used[v[i]] = 1;
        cout << v[i] << endl;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            cout << i << endl;
        }
    }
    return 0;
}
