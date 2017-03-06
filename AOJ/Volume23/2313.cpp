#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_V = 550;
constexpr int INF = (1 << 29);

int N;
int cap[MAX_V][MAX_V];
bool G[MAX_V][MAX_V];
bool used[MAX_V];

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    used[v] = 1;
    for (int i = 0; i < N; i++) {
        if (!used[i] && cap[v][i] > 0) {
            int d = dfs(i, t, min(f, cap[v][i]));
            if (d > 0) {
                cap[v][i] -= d;
                cap[i][v] += d;
                return d;
            }
        }
    }
    return 0;
}

int one_flow(int s, int t)
{
    memset(used, 0, sizeof(used));
    return dfs(s, t, 1);
}

int max_flow(int s, int t)
{
    int flow = 0;
    for (;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

void add_edge(int from, int to)
{
    cap[from][to] = cap[to][from] = 1;
}

void remove_edge(int from, int to)
{
    cap[from][to] = cap[to][from] = 0;    
}

int main()
{
    int E, Q;
    cin >> N >> E >> Q;
    
    for (int i = 0; i < E; i++) {
        int F, T;
        cin >> F >> T;
        add_edge(F - 1, T - 1);
    }
    
    int f = max_flow(0, N - 1);
    for (int i = 0; i < Q; i++) {
        int M, A, B;
        cin >> M >> A >> B;
        A -= 1; B -= 1;
        if (M == 1) {
            add_edge(A, B);
            f += one_flow(0, N - 1);
        } else {
            if (cap[A][B] != 0) swap(A, B);

            if (cap[A][B] == 0 && one_flow(A, B) == 0) {
                one_flow(N - 1, B);
                one_flow(A, 0);
                f -= 1;
            }
            
            remove_edge(A, B);
        }
        
        cout << f << endl;
    }
}
