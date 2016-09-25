#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-10)
#define INF (1e55)
#define lt(a, b) (a - b < -EPS)
#define equals(a, b) (fabs(a - b) < EPS)

struct Point {
    double x, y;

    Point () {}
    Point (double x, double y) : x(x), y(y) {}

    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    
    Point operator * (const double &k) const {
        return Point(x * k, y * k);
    }

    bool operator == (const Point &p) const {
        return (equals(x, p.x) && equals(y, p.y));
    }    
    
    bool operator < (const Point &p) const {
        if (!equals(x, p.x)) {
            return lt(x, p.x);
        } else {
            return lt(y, p.y);
        }
    }
};

double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b)
{
    return a.x * b.y - b.x * a.y;
}

double norm(const Point &p)
{
    return dot(p, p);
}

double abs(const Point &p)
{
    return sqrt(norm(p));
}

double dist(const Point &a, const Point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

#define COUNTER_CLOCKWISE +1
#define CLOCKWISE         -1
#define ONLINE_BACK       +2
#define ONLINE_FRONT      -2
#define ON_SEGMENT        +0
typedef Point Vector;

int ccw(const Point &p0, const Point &p1, const Point &p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)  return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS)   return ONLINE_BACK;
    if (norm(a) < norm(b))  return ONLINE_FRONT;
    return ON_SEGMENT;
}

struct Segment {
    Point s, t;
    Segment(){}
    Segment(Point s, Point t) : s(s), t(t) {}
};

typedef Segment Line;

Line perpendicular_bisector(const Point &a, const Point &b)
{
    double cx = (a.x + b.x) / 2.0;
    double cy = (a.y + b.y) / 2.0;
    Point p = Point(cx + (a.y - b.y), cy + (b.x - a.x));
    return Line(Point(cx, cy), p);
}

Point crosspointLL(const Line &a, const Line &b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

#define curr(G, i) (G[i % G.size()])
#define next(G, i) (G[(i + 1) % G.size()])
typedef vector<Point> Polygon;

Polygon convex_cut(const Polygon &pg, const Line &l)
{
    Polygon res;
    for (int i = 0; i < (int)pg.size(); i++) {
        Point cp = curr(pg, i), np = next(pg, i);
        if (ccw(l.s, l.t, cp) != -1) res.push_back(cp);
        if (ccw(l.s, l.t, cp) * ccw(l.s, l.t, np) < 0) {
            res.push_back(crosspointLL(Line(cp, np), l));
        }
    }
    return res;
}

bool check(Point a, Point b)
{
    if (lt(b.x, a.x)) swap(a, b);
    if (equals(a.x, b.x) && lt(b.y, a.y)) swap(a, b);
    if (equals(a.x, 0) && equals(b.x, 0)) return 1;
    if (equals(a.y, 0) && equals(b.y, 0)) return 1;
    if (equals(a.x, 4) && equals(b.x, 4)) return 1;
    if (equals(a.y, 4) && equals(b.y, 4)) return 1;
    return 0;
}

vector<Segment> make_segments(vector<Point> &ps)
{
    Polygon pg(4);
    pg[0] = Point(0, 0);
    pg[1] = Point(0, 4);
    pg[2] = Point(4, 4);
    pg[3] = Point(4, 0);

    vector<Segment> segs;
    
    int N = ps.size();
    for (int i = 0; i < N; i++) {
        Polygon p = pg;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            p = convex_cut(p, perpendicular_bisector(ps[i], ps[j]));
        }
        int M = p.size();
        for (int j = 0; j < M; j++) {
            if (check(curr(p, j), next(p, j))) continue;            
            segs.push_back(Segment(curr(p, j), next(p, j)));
        }
    }
    return segs;
}

struct Edge {
    int to;
    double cost;
    Edge (int to, double cost) : to(to), cost(cost) {}
    bool operator < (const Edge &e) const {
        return cost < e.cost;
    }
};

typedef vector<vector<Edge>> Graph;

bool isIntersectSS(const Segment &a, const Segment &b)
{
    Point s[2] = {a.s, a.t}, t[2] = {b.s, b.t};
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
	    ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}

bool isIntersectSP(const Segment &s, const Point &p)
{
    return (ccw(s.s, s.t, p) == 0);
}

Point crosspointSS(const Segment &a, const Segment &b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

Graph segment_arrangement(vector<Segment> &segs, vector<Point> &ps)
{
    Graph G;
    int N = segs.size();
    ps.clear();

    for (int i = 0; i < N; i++) {
	ps.push_back(segs[i].s);
	ps.push_back(segs[i].t);
	for (int j = i+1; j < N; j++) {
	    Vector a = segs[i].t - segs[i].s;
	    Vector b = segs[j].t - segs[j].s;
	    if (equals(cross(a, b), 0)) continue;            
	    if (isIntersectSS(segs[i], segs[j])) {
		ps.push_back(crosspointSS(segs[i], segs[j]));
	    }
	}
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());

    int N2 = ps.size();
    G.resize(N2);
    for (int i = 0; i < N; i++) {
	vector<pair<double,int>> vec;
	for (int j = 0; j < N2; j++) {
	    if (isIntersectSP(segs[i], ps[j])) {
		double d = dist(segs[i].s, ps[j]);
		vec.push_back(make_pair(d, j));
	    }
	}
	sort(vec.begin(), vec.end());
	for (int j = 0; j < (int)vec.size()-1; j++) {
	    int u = vec[j].second, v = vec[j+1].second;
	    double d = dist(ps[u], ps[v]);
	    G[u].push_back(Edge(v, d));
	    G[v].push_back(Edge(u, d));
	}
    }
    return G;
}

double solve(vector<Point> &ps)
{
    vector<Segment> v = make_segments(ps);
    vector<Point> p;
    Graph G = segment_arrangement(v, p);

    int N = p.size();    
    vector<vector<double>> d(N, vector<double>(N, INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            d[i][G[i][j].to] = G[i][j].cost;
        }
        d[i][i] = 0;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    double res = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!check(p[i], p[j]) && equals(p[i].x, 0) && equals(p[j].x, 4)) {
                res = min(res, d[i][j]);
            }
        }
    }    
    return res;
}

int main()
{
    int n;
    while (cin >> n, n) {
        vector<Point> ps(n);
        for (int i = 0; i < n; i++) {
            cin >> ps[i].x >> ps[i].y;
        }
        double res = solve(ps);
        if (n == 1 || res == INF) {
            puts("impossible");
        } else {
            printf("%.15f\n", res);
        }
    }
    return 0;
}
