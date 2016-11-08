#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_V = 55;
constexpr int INF = (1 << 29);

struct CAP {
    vector<int> c;
 
    CAP () { c = vector<int>(51); }
    
    CAP (int v) {
        c = vector<int>(51, v);
    }
     
    bool operator < (const CAP& w) const {
        return c > w.c;
    }
 
    bool operator > (const CAP& w) const {
        return c > w.c;
    }

    bool operator == (const CAP& w) const {
        return c == w.c;
    }
     
    CAP& operator += (const CAP& w) {        
        for (int i = 0; i < 51; i++) {
            c[i] += w.c[i];
        }
        return *this;
    }    
    
    CAP& operator -= (const CAP& w) {        
        for (int i = 0; i < 51; i++) {
            c[i] -= w.c[i];
        }
        return *this;
    }    
};

CAP min_cap(const CAP& a, const CAP& b)
{
    for (int i = 0; i <= 50; i++) {
        if (a.c[i] < b.c[i]) {
            return a;
        } else if (a.c[i] > b.c[i]) {
            return b;
        }
    }
    return a;
}

struct edge {
    int to;
    CAP cap;
    int rev;    
    edge(int to, CAP cap, int rev) :
        to{to}, cap{cap}, rev{rev} {}
};

vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, CAP cap)
{
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, CAP(0), G[from].size() - 1);
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
	int v = Q.front(); Q.pop();
	for (int i = 0; i < (int)G[v].size(); i++) {
	    edge &e = G[v][i];
	    if (e.cap > CAP(0) && level[e.to] < 0) {
		level[e.to] = level[v] + 1;
		Q.push(e.to);
	    }
	}
    }
}

CAP dfs(int v, int t, const CAP& f)
{
    if (v == t) return f;
    for (int &i = iter[v]; i < (int)G[v].size(); i++) {
	edge &e = G[v][i];
	if (e.cap > CAP(0) && level[v] < level[e.to]) {
	    CAP d = dfs(e.to, t, min_cap(f, e.cap));
	    if (d > CAP(0)) {
		e.cap -= d;
		G[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}

CAP max_flow(int s, int t)
{
    CAP flow;
    for (;;) {
	bfs(s);
	if (level[t] < 0) return flow;
	memset(iter, 0, sizeof(iter));
	CAP f;
	while ((f = dfs(s, t, CAP(INF))) > CAP(0)) {
	    flow += f;
	}
    }
}

void init(int N)
{
    for (int i = 0; i < N; i++) {
        G[i].clear();
    }
}

pair<int, int> get_num(const string& s)
{
    int j = -1;
    int N = s.size();
    for (int i = 0; i < N; i++) {
        if (s[i] == 'x') {
            j = i;
            break;
        }
    }
    if (j == -1) {
        return {50, stoi(s)};
    } else {
        int v = (j + 1 == N ? 1 : stoi(s.substr(j + 2)));
        return {50 - v, (j == 0 ? 1 : stoi(s.substr(0, j)))};
    }   
}

CAP get_cap(const string& p)
{
    CAP cap;
    string s;
    for (auto& v : p) {
        if (v == '+') {
            auto r = get_num(s);
            cap.c[r.first] = r.second;
            s.clear();
        } else {
            s += v;
        }
    }

    if (!s.empty()) {
        auto r = get_num(s);
        cap.c[r.first] = r.second;
    }        
    return cap;
}

int main()
{
    int N, M;
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        init(N);
        
        int S = 0, T = N - 1;
        int u, v;
        string p;
        for (int i = 0; i < M; i++) {
            cin >> u >> v >> p;
            u--; v--;
            CAP c = get_cap(p);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }

        auto f = max_flow(S, T);
        
        vector<pair<int, int>> res;
        for (int i = 0; i <= 50; i++) {
            if (f.c[i] > 0) {
                res.emplace_back(f.c[i], 50 - i);              
            }
        }

        if (res.size() == 0) {
            cout << 0 << endl;
        } else {
            for (int i = 0; i < (int)res.size(); i++) {
                if (i > 0) cout << "+";
                if (res[i].second == 0 || res[i].first != 1) {
                    cout << res[i].first;   
                }
                if (res[i].second != 0) {
                    cout << "x";
                    if (res[i].second > 1) {
                        cout << "^" << res[i].second;
                    }
                }
            }
            cout << endl;
        }
    }        
    return 0;
}
