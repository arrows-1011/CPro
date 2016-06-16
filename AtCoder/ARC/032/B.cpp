#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

vector<int> G[MAX];
bool visited[MAX];

void dfs(int v)
{
    for (int i = 0; i < (int)G[v].size(); i++) {
        int to = G[v][i];
        if (!visited[to]) {
            visited[to] = 1;
            dfs(to);
        }
    }
}

int main()
{    
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            res++;
            dfs(i);
        }
    }
    cout << res - 1 << endl;
    return 0;
}
