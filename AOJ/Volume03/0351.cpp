#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    int to, cost;
    edge() {}
    edge(int to, int cost) : to{to}, cost{cost} {}
};

struct State {
    int v, c;
    State() {}
    State(int v, int c) : v{v}, c{c} {}

    bool operator < (const State& st) const {
        return c > st.c;
    };
};

int main()
{
    int N, R;
    cin >> N >> R;
    
    constexpr int INF = (1 << 29);
    vector<vector<edge>> G(N);
    vector<vector<int>> c(N, vector<int>(N, INF));
    for (int i = 0; i < R; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        s--; t--;
        c[s][t] = c[t][s] = d;
        G[s].emplace_back(t, d);
        G[t].emplace_back(s, d);
    }

    vector<vector<int>> d(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        d[i][i] = 0;
        priority_queue<State> pq;
        pq.push(State(i, 0));

        while (!pq.empty()) {
            State st = pq.top(); pq.pop();
            int v = st.v, c = st.c;
            if (c > d[i][v]) continue;
            for (auto& e : G[v]) {
                if (d[i][v] + e.cost < d[i][e.to]) {
                    d[i][e.to] = d[i][v] + e.cost;
                    pq.push(State(e.to, d[i][e.to]));
                }
            }
        }
    }
    
    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mx = max(mx, d[i][j]);            
        }
    }
    
    vector<int> a, b;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (mx == d[i][j]) {
                a.emplace_back(i);
                b.emplace_back(j);
            }
        }
    }
    
    vector<int> town;
    for (int i = 0; i < N; i++) {
        bool quiet = 1;
        for (int j = 0; j < (int)a.size(); j++) {
            if (d[a[j]][i] + d[i][b[j]] == mx) {
                quiet = 0;
                break;
            }
        }
        if (quiet) {
            town.emplace_back(i + 1);
        }
    }
    
    int n = town.size();
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << town[i] << endl;
    }
    return 0;
}
