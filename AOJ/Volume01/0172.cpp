#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 15
#define INF 1e9
 
int N,M,light,swt[MAX];
vector<int> G[MAX];
 
void init()
{
    for (int i = 0; i < MAX; i++) {
	G[i].clear();
	swt[i] = 0;
    }
}
 
struct State {
    int v, l;
    State(){}
    State(int v, int l) : v(v), l(l) {}
};
 
void solve()
{
    int d[MAX][1<<MAX];
    State path[MAX][1<<MAX];
    fill(d[0], d[0]+MAX*(1<<MAX), INF);
 
    bool found = false;
    d[0][light] = 0;
    queue<State> Q;
    Q.push(State(0, light));
    while (!Q.empty()) {
	State s = Q.front(); Q.pop();
	int v = s.v;
	if (v == N-1 && s.l == (1<<(N-1))) {
	    found = true;
	    break;
	}
	for (int i = 0; i < (int)G[v].size(); i++) {
	    int to = G[v][i];
	    if (d[v][s.l] + 1 < d[to][s.l] && (s.l >> to & 1)) {
		d[to][s.l] = d[v][s.l] + 1;
		path[to][s.l] = s;
		Q.push(State(to,s.l));
	    }
	}
	for (int i = 0; i < N; i++) {
	    if (i == v) continue;
	    if (swt[v] >> i & 1) {
		int nl = s.l;
		if (s.l >> i & 1) {
		    nl -= (1<<i);
		} else {
		    nl |= (1<<i);
		}
		if (d[v][s.l] + 1 < d[v][nl]) {
		    d[v][nl] = d[v][s.l] + 1;
		    path[v][nl] = s;
		    Q.push(State(v,nl));
		}
	    }
	}
    }
    if (found) {
	cout << "You can go home in " << d[N-1][1<<(N-1)] << " steps." << endl;
	int v = N-1,l = 1<<(N-1);
	vector<State> vec;
	vec.push_back(State(N-1,(1<<(N-1))));
	while (true) {
	    if (v == 0 && l == light) break;
	    State next = path[v][l];
	    vec.push_back(next);
	    v = next.v; l = next.l;
	}
	reverse(vec.begin(), vec.end());
	int size = vec.size();
	for (int i = 0; i < size-1; i++) {
	    State cs = vec[i],ns = vec[i+1];
	    if (cs.v == ns.v) {
		int j;
		bool on = false, off = false;
		for (j = 0; j < N; j++) {
		    if ((cs.l >> j & 1) && !(ns.l >> j & 1)) {
			off = true;
			break;
		    }
		    if (!(cs.l >> j & 1) && (ns.l >> j & 1)) { 
			on = true;
			break;
		    }
		}
		if (on) {
		    cout << "Switch on room " << j+1 << "." << endl;
		} else if (off) {
		    cout << "Switch off room " << j+1 << "." << endl;
		}
	    } else {
		cout << "Move to room " << ns.v+1 << "." << endl;
	    }
	}
    } else {
	for (int i = 0; i < (1<<N); i++) {
	    if (d[N-1][i] != INF) {
		cout << "You can not switch off all lights." << endl;
		return;
	    }
	}
	cout << "Help me!" << endl;
    }
}
 
int main()
{
    int s, t, k, r;
    while (cin >> N >> M, (N | M)) {
	init();
	for (int i = 0; i < M; i++) {
	    cin >> s >> t; s--; t--;
	    G[s].push_back(t);
	    G[t].push_back(s);
	}
	int x;
	light = 0;
	for (int i = 0; i < N; i++) {
	    cin >> x;
	    if (x == 1) light |= (1<<i);
	}
	for (int i = 0; i < N; i++) {
	    cin >> k;
	    for (int j = 0; j < k; j++) {
		cin >> r; r--;
		swt[i] |= (1<<r);
	    }
	}
	solve();
    }
    return 0;
}
