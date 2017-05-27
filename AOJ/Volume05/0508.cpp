#include <iostream>
#include <vector>

constexpr int MAX = 100;

bool visited[MAX];

int dfs(int v, const std::vector<std::vector<int>> &G)
{
    visited[v] = 1;
    int res = 0;
    for (int to : G[v]) {
        if (!visited[to]) {
            res = std::max(res, dfs(to, G) + 1);
        }
    }
    visited[v] = 0;
    return res;

}

int main()
{
    int N;
    while (1) {
        std::cin >> N;
        if (N == 0) {
            break;
        }
        std::vector<std::vector<int>> G(MAX);
        for (int i = 0; i < N; i++) {
            int a, b;
            std::cin >> a >> b;
            a--; b--;
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        }

        int res = 0;
        for (int i = 0; i < MAX; i++) {
            std::fill(visited, visited + MAX, 0);
            res = std::max(res, dfs(i, G) + 1);
        }
    
        std::cout << res << std::endl;
    }
    return 0;
}
