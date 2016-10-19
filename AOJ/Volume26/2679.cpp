#include <bits/stdc++.h>

using namespace std;

struct Weight {
    vector<int> c;

    Weight () { c = vector<int>(52); }
    Weight (int v) : c{52, v} {}
    Weight (const vector<int>& c) : c{c} {}

    void init(int v) {
        for (int i = 0; i < 52; i++) {
            c[i] = v;
        }
    }
    
    bool operator < (const Weight& w) const {
        return c > w.c;
    }

    bool operator > (const Weight& w) const {
        return c > w.c;
    }

    bool operator == (const Weight& w) const {
        return c == w.c;
    }
    
    Weight& operator += (const Weight& w) {        
        for (int i = 0; i < 52; i++) {
            c[i] += w.c[i];
        }
        return *this;
    }

    Weight& operator * (int k) {
        for (int i = 0; i < 52; i++) {
            c[i] *= k;            
        }
        return *this;
    }

    Weight& operator - () {
        for (int i = 0; i < 52; i++) {
            c[i] = -c[i];
        }        
        return *this;
    }
};

Weight operator + (const Weight& a, const Weight& b)
{
    Weight w;
    for (int i = 0; i < 52; i++) {
        w.c[i] = a.c[i] + b.c[i];
    }
    return w;
}

Weight operator - (const Weight& a, const Weight& b)
{
    Weight w;
    for (int i = 0; i < 52; i++) {
        w.c[i] = a.c[i] - b.c[i];
    }
    return w;
}

#define MAX_V 1010
#define INF 1e9
using pwi = pair<Weight, int>;

struct edge {
    int to;
    int cap;
    Weight cost;
    int rev;    
    
    edge(int to, int cap, Weight cost, int rev) :
        to{to}, cap{cap}, cost{cost}, rev{rev} {}
};

int V;
Weight h[MAX_V], dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];
vector<edge> G[MAX_V];

void add_edge(int from, int to, int cap, Weight cost)
{
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size()-1));
}

void init(Weight* w, int v)
{
    for (int i = 0; i < V; i++) {
        w[i].init(v);
    }
}

Weight min_cost_flow(int s, int t, int f)
{
    Weight res;
    init(h, 0);
    while (f > 0) {
	priority_queue<pwi> pq;
	init(dist, INF);
        dist[s].init(0);
	pq.push(pwi(Weight(), s));
	while (!pq.empty()) {
	    pwi p = pq.top(); pq.pop();
	    int v = p.second;
	    if (dist[v] < p.first) continue;
	    for (int i = 0; i < (int)G[v].size(); i++) {
		edge &e = G[v][i];
		
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) { 
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
		    prevv[e.to] = v; preve[e.to] = i;
		    pq.push({dist[e.to], e.to});
                }
	    }
	}
        
        Weight inf(INF);
	if (dist[t] == inf) return -1;
	for (int v = 0; v < V; v++) {
	    h[v] += dist[v];
	}
	int d = f;
	for (int v = t; v != s; v = prevv[v]) {
	    d = min(d, G[prevv[v]][preve[v]].cap);
	}
	f -= d;
	res += h[t] * d;        
	for (int v = t; v != s; v = prevv[v]) {
	    edge &e = G[prevv[v]][preve[v]];
	    e.cap -= d;
	    G[v][e.rev].cap += d;
	}
    }
    return res;
}

int get_num(char x)
{
    if (isupper(x)) {
        return (x - 'A');
    }
    return 26 + (x - 'a');
}

char get_char(int x)
{
    if (x < 26) {
        return (x + 'A');
    }
    return (x - 26 + 'a');
}

int main()
{
    int N;
    cin >> N;
    
    int S = 2 * N, T = S + 1;
    V = T + 1;
    for (int i = 0; i < N; i++) {
        add_edge(S, i, 1, Weight());
        add_edge(i + N, T, 1, Weight());
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            Weight w;
            w.c[get_num(c)] = -1;
            add_edge(i, j + N, 1, w);
        }
    }

    auto res = min_cost_flow(S, T, N);
    for (int i = 0; i < 52; i++) {
        if (res.c[i] < 0) {
            for (int j = 0; j < -res.c[i]; j++) {
                cout << get_char(i);
            }
        }
    }
    cout << endl;
    return 0;
}
