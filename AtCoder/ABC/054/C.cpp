#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> G[8];

int dfs(int v, int vis)
{
    if (vis == (1 << N) - 1) {
        return 1;
    }
    
    int res = 0;
    for (int next : G[v]) {
        if (vis >> next & 1) continue;
        res += dfs(next, vis | (1 << next));
    }
    return res;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1; b -= 1;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    cout << dfs(0, (1 << 0)) << endl;
    return 0;
}
