#include <bits/stdc++.h>

using namespace std;

#define MAX 100
#define INF (1<<29)

int N, cost[MAX][MAX];

int get_sat(set<int> &inv)
{
    int sat = 0;
    for (auto &i: inv) {
        int s = INF;
        for (auto &j: inv) {
            if (i == j) continue;
            s = min(s, cost[i][j]);
        }
        sat += s;
    }
    return sat;
}

map<set<int>, int> memo;

int dfs(set<int> inv)
{
    int res = 0;
    if (memo.count(inv) > 0) {
        return memo[inv];
    }        
    if (inv.size() >= 2) {
        res = get_sat(inv);
    }
    for (int i = 0; i < N; i++) {
        bool ok = 1;
        for (auto &j: inv) {
            if (cost[i][j] == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            set<int> ninv = inv;
            ninv.insert(i);
            res = max(res, dfs(ninv));
        }            
    }
    return (memo[inv] = res);
}

int main()
{
    int M, a, b, c;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--; b--;
        cost[a][b] = cost[b][a] = c;
    }    
    cout << dfs(set<int>()) << endl;
    return 0;
}
