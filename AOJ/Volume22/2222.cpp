#include <bits/stdc++.h>

using namespace std;

#define MAX_V 1145
typedef pair<int, int> pii;
typedef long long ll;
const ll MOD = ((1e9) + 7);

int N, cmp[MAX_V];
bool used[MAX_V];
vector<int> G[MAX_V], rG[MAX_V], vs;

void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int)G[v].size(); i++) {
	if (!used[G[v][i]]) {
            dfs(G[v][i]);
        }
    }
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    used[v] = 1;
    cmp[v] = k;
    for (int i = 0; i < (int)rG[v].size(); i++) {
	if (!used[rG[v][i]]) {
            rdfs(rG[v][i], k);
        }
    }
}

int scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 0; v < N; v++) {
	if (!used[v]) {
            dfs(v);
        }
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
	if (!used[vs[i]]) {
            rdfs(vs[i], k++);
        }
    }
    return k;
}

vector<int> nG[MAX_V];

ll solve(int v)
{
    ll res = 1;
    for (int i = 0; i < (int)nG[v].size(); i++) {
        res *= solve(nG[v][i]);
        res %= MOD;
    }
    res += 1;
    return res % MOD;
}

int main()
{
    int M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b; a--; b--;
        add_edge(a, b);
    }
    
    auto K = scc();
    
    set<pii> st;
    int deg[MAX_V] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            int from = cmp[i], to = cmp[G[i][j]];
            if (from != to && st.count(pii(from, to)) == 0) {
                st.insert(pii(from, to));
                nG[to].push_back(from);
                deg[from]++;
            }
        }
    }
    
    ll res = 1;    
    for (int i = 0; i < K; i++) {
        if (deg[i] == 0) {
            res *= solve(i);
            res %= MOD;
        }
    }

    cout << res << endl;
    return 0;
}
