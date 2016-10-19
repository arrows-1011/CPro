#include <bits/stdc++.h>

using namespace std;

#define MAX_V 5432
#define INF 1e9
typedef pair<int, int> pii;

struct edge {
    int to, cap, cost, rev;
    edge(int to, int cap, int cost, int rev) :
        to(to), cap(cap), cost(cost), rev(rev) {}
};

int V, h[MAX_V], dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];
vector<edge> G[MAX_V];

void add_edge(int from, int to, int cap, int cost)
{
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    fill(h, h + V, 0);
    while (f > 0) {
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        fill(dist, dist + V, INF);
        dist[s] = 0;
        Q.push(pii(0, s));
        while (!Q.empty()) {
            pii p = Q.top(); Q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v; preve[e.to] = i;
                    Q.push(pii(dist[e.to], e.to));
                }
            }
        }
        if (dist[t] == INF) return -1;
        for (int v = 0; v < V; v++) {
            h[v] += dist[v];
        }        
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int levenshtein_distance(string& s, string& t,
                         int incost = 1, int rmcost = 1, int recost = 1)
{
    int N = s.size(), M = t.size();
    int dp[N + 1][M + 1];

    for (int i = 0; i <= N; i++) {
        dp[i][0] = i * incost;
    }
    for (int i = 0; i <= M; i++) {
        dp[0][i] = i * rmcost;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int rcost = (s[i - 1] == t[j - 1] ? 0 : recost);
            dp[i][j] = min(dp[i - 1][j] + incost,
                           min(dp[i][j - 1] + rmcost, dp[i - 1][j - 1] + rcost));
        }
    }
    return dp[N][M];
}

int main()
{
    int N, M;
    cin >> N >> M;
    cin.ignore();
    
    set<string> text;
    map<string, int> cnt;
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        
        stringstream ss(s);
        while (ss >> s) {
            cnt[s]++;
            text.insert(s);
        }
    }
    
    vector<string> dic(M);
    for (int i = 0; i < M; i++) {
        cin >> dic[i];
    }

    N = text.size();
    int S = N + M, T = S + 1;
    V = T + 1;
    
    for (int i = 0; i < N; i++) {
        add_edge(S, i, 1, 0);
    }

    for (int i = 0; i < M; i++) {
        add_edge(N + i, T, 1, 0);
    }
    
    int i = 0;
    for (string str : text) {
        for (int j = 0; j < M; j++) {
            int ld = levenshtein_distance(str, dic[j]);     
            add_edge(i, N + j, 1, ld * cnt[str]);            
        }
        i++;
    }
    cout << min_cost_flow(S, T, N) << endl;
    return 0;
}
