#include <bits/stdc++.h>

using namespace std;

#define MAX 100

vector<int> G[MAX];

int dfs(int curr, int prev, vector<int> &h)
{
    int res = 0;
    for (int i = 0; i < (int)G[curr].size(); i++) {
        int to = G[curr][i];
        if (to == prev) continue;
        res += dfs(to, curr, h);
    }

    if (h[curr] == 1 || res > 0) {
        return res + 2;
    }
    return 0;
}

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    int a, b;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << max(0, dfs(X - 1, -1, h) - 2) << endl;
    return 0;
}
