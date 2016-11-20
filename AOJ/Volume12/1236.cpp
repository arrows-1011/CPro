#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 114;

int v;
int deg[MAX], dv[MAX];
vector<int> res[MAX];

void dfs(size_t& idx, int depth, const vector<int>& q)
{
    deg[v] += q[idx];
    dv[depth] = v;
    
    int nv = v++;
    
    while (idx < q.size() && deg[nv] > 0) {
        const int val = q[++idx];
        if (val > 0) {
            deg[nv]--; deg[v]--;
            res[nv].emplace_back(v);
            res[v].emplace_back(nv);
            dfs(idx, depth + 1, q);
        } else {
            int u = dv[depth + val];
            deg[u]--; deg[nv]--;
            res[u].emplace_back(nv);
            res[nv].emplace_back(u);
        }
    }
}

void init(int N)
{
    v = 0;
    for (int i = 0; i < N; i++) {
        res[i].clear();
        deg[i] = 0;
    }
}

int main()
{
    int Tc;
    cin >> Tc;
    while (Tc--) {        
        int x, N = 0;
        vector<int> q;
        while (cin >> x, x != 0) {
            N += (x > 0);
            q.emplace_back(x);
        }
        
        init(N);
        size_t idx = 0;
        dfs(idx, 0, q);

        for (int i = 0; i < N; i++) {
            cout << i + 1;
            sort(res[i].begin(), res[i].end());
            for (const auto& r : res[i]) {
                cout << " " << r + 1;
            }
            cout << endl;;
        }
    }
    return 0;
}
