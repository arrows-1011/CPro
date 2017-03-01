#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = (1e-10);
constexpr double INF = 2525210;
#define equals(a, b) (fabs(a - b) < EPS)

vector<int> par, rnk;

void init(int n)
{
    par.resize(n); rnk.resize(n);
    for (int i = 0; i < n; i++) {
	par[i] = i;
	rnk[i] = 0;
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

    if (rnk[x] < rnk[y]) {
	par[x] = y;
    } else {
	par[y] = x;
	if (rnk[x] == rnk[y]) {
	    rnk[x]++;
	}
    }
}

bool same(int x, int y)
{
    return (find(x) == find(y));
}

struct Edge {
    int u, v;
    double w;

    Edge() {}
    Edge(int u, int v, double w) :
        u{u}, v{v}, w{w} {}
};

struct Data {
    int u, v;
    double c, t;

    Data() {}
    Data(int u, int v, double c, double t) :
        u{u}, v{v}, c{c}, t{t} {}
};

int N, M;
vector<Data> d;
vector<Edge> es;

double kruskal()
{
    sort(es.begin(), es.end(), [](const Edge& e1, const Edge& e2) {
            return e1.w < e2.w;
    });
    
    init(N); 
    double tw = 0;
    for (Edge& e : es) {
	if (!same(e.u, e.v) || e.w < 0) {
	    unite(e.u, e.v);
            tw += e.w;
        }
    }    
    return tw;
}

bool c(double x)
{
    for (int i = 0; i < M; i++) {
        es[i].u = d[i].u;
        es[i].v = d[i].v;
        es[i].w = d[i].c - x * d[i].t;
    }
    return kruskal() <= 0;
}

double solve()
{
    double lb = 0, ub = INF;
    for (int i = 0; i < 50; i++) {
        double mid = (lb + ub) / 2;
        if (c(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    return ub;
}

int main()
{
    scanf("%d %d", &N, &M);
    d.resize(M); es.resize(M);
    
    for (int i = 0; i < M; i++) {
        scanf("%d %d %lf %lf", &d[i].u, &d[i].v, &d[i].c, &d[i].t);
    }
    
    auto res = solve();
    printf("%.15f\n", res);
    return 0;
}
