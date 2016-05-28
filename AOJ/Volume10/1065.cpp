#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
#define INF INT_MAX
typedef pair<int, int> pii;

struct Edge {
    int from, to, cost;
    Edge(int from, int to, int cost) :
        from(from), to(to), cost(cost) {}
};

int N, M;
vector<Edge> G[MAX], cycle;

int color[MAX];
 
void dfs(int v, vector<Edge> u)
{
    color[v] = 0;
    for(int i = 0; i < (int)G[v].size(); i++) {
        Edge e = G[v][i];
        int to = e.to;
        u.push_back(e);
        if (color[to] == -1) {
            dfs(to, u);
        } else if(color[to] == 0) {
            cycle = u;
            throw 0;            
        }
        u.pop_back();
    }
    color[v] = 1;
}

bool is_cycle_detect()
{
    vector<Edge> vec;
    memset(color, -1, sizeof(color));
    for (int i = 0; i < N; i++) {
        try {
            if (color[i] == -1) {
                dfs(i, vec);
            }
        } catch (...) {
            break;
        }
        vec.clear();
    }
    return (cycle.size() > 0);
}

void init()
{
    cycle.clear();
    for (int i = 0; i < MAX; i++) {
        G[i].clear();
    }
}

class Union_Find {
  public:
    int par[MAX], rank[MAX], size[MAX], gnum;
    
    Union_Find (int N) {
        gnum = N;
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return;
        
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        gnum--;
    }

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }

    int getSize(int x)
    {
        return size[find(x)];
    }

    int groups()
    {
        return gnum;
    }
};

int main()
{
    int s, t, cost;
    while (cin >> N >> M, N) {
        int res = 0, min_cost = INF;
        init();
        Union_Find uf(N);
        for (int i = 0; i < M; i++) {
            cin >> s >> t >> cost;
            if (cost > 0) {
                G[s].push_back(Edge(s, t, cost));
                uf.unite(s, t);
                min_cost = min(min_cost, cost);
            } else {
                res += cost;
            }                
        }
        
        if (uf.gnum == 1) {
            if (is_cycle_detect()) {
                min_cost = INF;
                set<pii> st;
                vector<int> v;
                for (int i = 0; i < (int)cycle.size(); i++) {
                    v.push_back(cycle[i].cost);
                    st.insert(pii(cycle[i].from, cycle[i].to));
                }
                sort(v.begin(), v.end());
                min_cost = v[0] + v[1];
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < (int)G[i].size(); j++) {
                        Edge &e = G[i][j];                    
                        if (st.count(pii(e.from, e.to)) == 0) {
                            min_cost = min(min_cost, e.cost);
                        }
                    }
                }
            } 
        } else {
            min_cost = 0;
        }
        cout << res + min_cost << endl;
    }
    return 0;
}
