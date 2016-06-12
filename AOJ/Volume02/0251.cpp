#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

vector<int> G[MAX];
bool visited[MAX];

void init()
{
    for (int i = 0; i < MAX; i++) {
        G[i].clear();
        visited[i] = 0;
    }
}

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

bool check(int N)
{
    for (int i = 0; i < N; i++) {
        if (G[i].size() >= 3) return 0;
        if (!visited[i] && G[i].size() <= 1) {
            visited[i] = 1;
            dfs(i);
        }        
    }
    return (count(visited, visited + N, 0) == 0);
}

int main()
{
    int N, M;
    while (cin >> N >> M, N) {
        int a, b;
        init();
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cout << (check(N) ? "yes" : "no") << endl;
    }
    return 0;
}
