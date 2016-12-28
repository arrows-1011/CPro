#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, cost;
    Edge() {}
    Edge(int to, int cost) : to{to}, cost{cost} {}
};

constexpr int MAX = 10000;
constexpr int MAX_T = 200;
constexpr int INF = (1 << 29);

vector<Edge> G[MAX];

struct State {
    int w, v, t, n;
    State() {}
    State(int w, int v, int t, int n) : w{w}, v{v}, t{t}, n{n} {}

    bool operator < (const State& s) const {
        return w > s.w;
    }
};

int d[MAX][MAX_T + 1][3];

int dijkstra(int N, int X, const vector<int>& T)
{
    priority_queue<State> pq;
    pq.push(State(0, 0, 0, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k < 3; k++) {
                d[i][j][k] = INF;
            }
        }
    }

    d[0][0][0] = 0;

    while (!pq.empty()) {
        State st = pq.top(); pq.pop();
        int v = st.v, t = st.t, n = st.n;

        if (d[v][t][n] < st.w) continue;
        
        if (v == N - 1) {
            return d[v][t][n];
        }
        
        for (const auto& e : G[v]) {
            int nt = min(X, t + e.cost);
            int ncost = d[v][t][n] + e.cost;
            if (T[e.to] == n) {
                if (ncost < d[e.to][0][n]) {
                    d[e.to][0][n] = ncost;
                    pq.push(State(d[e.to][0][n], e.to, 0, n));
                }
            } else {
                if (T[e.to] == 1) {
                    if (ncost < d[e.to][nt][n]) {
                        d[e.to][nt][n] = ncost;
                        pq.push(State(d[e.to][nt][n], e.to, nt, n));
                    }
                } else {
                    if (nt != X) continue;
                    if (ncost < d[e.to][0][T[e.to]]) {
                        d[e.to][0][T[e.to]] = ncost;
                        pq.push(State(d[e.to][0][T[e.to]], e.to, 0, T[e.to]));
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    
    for (int i = 0; i < M; i++) {
        int A, B, D;
        cin >> A >> B >> D;
        A--; B--;
        G[A].emplace_back(B, D);
        G[B].emplace_back(A, D);
    }
    cout << dijkstra(N, X, T) << endl;
    return 0;
}
