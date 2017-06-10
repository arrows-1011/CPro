#include <iostream>
#include <vector>
#include <cstring>

using vec = std::vector<int>;
using mat = std::vector<vec>;
constexpr int MAX_H = 8;
constexpr int MAX_W = 8;

bool visited[MAX_H][MAX_W];

bool is_reach(int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) return 0;
        }
    }
    return 1;
}

bool dfs(int x, int y, int sum, int idx, const mat &p,
         const std::vector<std::pair<int, int>> &start)
{
    int N = p.size();
    if (sum == 0) {
        if (idx == (int)start.size()) {            
            return is_reach(N);
        }

        int nx = start[idx].first;
        int ny = start[idx].second;
        
        visited[ny][nx] = 1;
        bool res = dfs(nx, ny, p[ny][nx], idx + 1, p, start);
        visited[ny][nx] = 0;
        return res;
    } 

    constexpr int dx[] = {-1, 0, 1, 0};
    constexpr int dy[] = {0, -1, 0, 1};        
    
    bool res = 0;    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= N ||
            p[ny][nx] < 0 || sum + p[ny][nx] > 0) {
            continue;
        }
        if (!visited[ny][nx]) {
            visited[ny][nx] = 1;
            res |= dfs(nx, ny, sum + p[ny][nx], idx, p, start);
            visited[ny][nx] = 0;
        }
    }

    return res;
}

int main()
{
    while (1) {
        int N;
        std::cin >> N;
        if (N == 0) {
            break;
        }
        
        mat p(N, vec(N));
        std::vector<std::pair<int, int>> start;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> p[i][j];            
                if (p[i][j] < 0) {
                    start.emplace_back(j, i);
                }
            }
        }
        
        memset(visited, 0, sizeof(visited));
        std::cout << (dfs(-1, -1, 0, 0, p, start) ? "YES" : "NO") << std::endl;
    }
    return 0;
}
