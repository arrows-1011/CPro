#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    
    vector<int> res;
    vector<bool> del(N);
    for (int i = N - 1; i >= 0; i--) {
        bool d = 1;
        for (auto& v : G[i]) {
            if (del[v]) {
                d = 0;
                break;
            }
        }
        if (d) {
            del[i] = 1;
            res.emplace_back(0);
        } else {
            res.emplace_back(1);
        }
    }
    
    bool one = 0;
    for (int i = 0; i < N; i++) {
        if (one) {
            cout << res[i];
        } else {
            if (res[i] == 1) {
                one = 1;
                cout << 1;
            }
        }
    }
    cout << endl;
    return 0;
}
