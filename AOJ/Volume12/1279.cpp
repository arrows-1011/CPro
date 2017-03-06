#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = (1e-6);
constexpr double PI = acos(-1);
#define equals(a, b) (fabs(a - b) < EPS)

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) : x{x}, y{y} {}
 
    Point operator + (const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator - (const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }
    
    Point operator * (const double& k) const
    {
        return Point(x * k, y * k);
    }
    
    Point operator / (const double& k) const
    {
        return Point(x / k, y / k);
    }

    bool operator < (const Point& p) const
    {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point& p) const
    {
        return (equals(x, p.x) && equals(y, p.y));
    }
};

using Vector = Point;

istream& operator >> (istream& is, Point& p)
{ 
    return is >> p.x >> p.y;
}

double dot(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(const Point& a, const Point& b)
{
    return a.x * b.y - b.x * a.y;
}

double norm(const Point& p)
{
    return dot(p, p);
}

double abs(const Point& p)
{
    return sqrt(norm(p));
}

double dist(const Point& a, const Point& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double get_angle(const Point& a, const Point& b)
{
    return acos(dot(a, b)) / abs(a) / abs(b);
}

constexpr int COUNTER_CLOCKWISE = +1;
constexpr int CLOCKWISE         = -1;
constexpr int ONLINE_BACK       = +2;
constexpr int ONLINE_FRONT      = -2;
constexpr int ON_SEGMENT        = +0;

int ccw(const Point& p0, const Point& p1, const Point& p2)
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
    Segment() {}
    Segment(Point s, Point t) : s{s}, t{t} {}
};

bool intersect_SP(const Segment& s, const Point& p)
{
    return (ccw(s.s, s.t, p) == 0);
}

bool intersect_SS(const Segment& a, const Segment& b)
{
    Point s[2] = {a.s, a.t}, t[2] = {b.s, b.t};
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
            ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}

Point crosspoint_SS(const Segment& a, const Segment& b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    Point p =  a.s + va * cross(vb, b.t - a.s) * (1.0 / d);    
    return Point{(double)((int)(p.x + EPS)), (double)((int)(p.y + EPS))};
}

struct Edge {
    int to;
    double cost;
    Edge(int to, double cost) : to{to}, cost{cost} {}
    
    bool operator < (const Edge& e) const
    {
        return cost < e.cost;
    }
};

using Graph = vector<vector<Edge>>;

Graph segment_arrangement(vector<Segment>& segs, vector<Point>& ps)
{
    Graph G;
    int N = segs.size();
    ps.clear();

    for (int i = 0; i < N; i++) {
        ps.emplace_back(segs[i].s);
        ps.emplace_back(segs[i].t);
        for (int j = i + 1; j < N; j++) {
            Vector a = segs[i].t - segs[i].s;
            Vector b = segs[j].t - segs[j].s;
            if (equals(cross(a, b), 0)) {
                continue;
            }
            if (intersect_SS(segs[i], segs[j])) {
                ps.emplace_back(crosspoint_SS(segs[i], segs[j]));
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
            if (intersect_SP(segs[i], ps[j])) {
                double d = dist(segs[i].s, ps[j]);
                vec.emplace_back(d, j);
            }
        }
        sort(vec.begin(), vec.end());
        for (int j = 0; j < (int)vec.size() - 1; j++) {
            int u = vec[j].second, v = vec[j + 1].second;
            double d = dist(ps[u], ps[v]);
            G[u].emplace_back(v, d);
            G[v].emplace_back(u, d);
        }
    }
    return G;
}

bool pass(Segment& s, vector<Segment>& sign)
{
    for (Segment t : sign) {
        if (intersect_SS(s, t)) {
            Point a = crosspoint_SS(s, t);
            Point b = (a == s.s ? s.t : s.s);
            Point c = (a == t.s ? t.t : t.s);                        

            if (dot(a - b, c - a) > -EPS) {
                return 0;
            }            
        }
    }
    return 1;
}

int main()
{
    int N;    
    Point s, t;
    while (cin >> N, N > 0) {
        cin >> s >> t;
        vector<Segment> segs(N);
        for (int i = 0; i < N; i++) {
            cin >> segs[i].s >> segs[i].t;
        }

        vector<Segment> sign, road;
        for (int i = 0; i < N; i++) {
            bool cf[2] = {};
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                cf[0] |= intersect_SP(segs[j], segs[i].s);
                cf[1] |= intersect_SP(segs[j], segs[i].t);
            }
            
            if (cf[0] && cf[1]) {
                road.emplace_back(segs[i]);
            } else {
                sign.emplace_back(segs[i]);
            }
        }        
          
        vector<Point> ps;
        Graph g = segment_arrangement(road, ps);

        int n = ps.size(), sp = -1, tp = -1;
        for (int i = 0; i < n; i++) {
            if (s == ps[i]) sp = i;
            if (t == ps[i]) tp = i;
        }
        
        using P = tuple<double, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push(P(0, sp));

        vector<int> path(n, -1);
        
        constexpr double INF = (1e55);
        vector<double> d(n, INF);
        d[sp] = 0;
        
        while (!pq.empty()) {
            double c;
            int v;
            
            tie(c, v) = pq.top(); pq.pop();

            if (v == tp) break;
            if (d[v] < c) continue;
            
            for (Edge e : g[v]) {
                int to = e.to;
                double nc = e.cost + c;
                
                Segment seg{ps[v], ps[to]};
                if (!pass(seg, sign)) {
                    continue;
                }

                if (nc < d[to]) {
                    d[to] = nc;
                    path[to] = v;
                    pq.push(P(nc, to));
                }                
            }
        }

        vector<int> res;
        int p = tp;
        while (p != -1) {
            res.emplace_back(p);            
            p = path[p];            
        }

        if (equals(d[tp], INF)) {
            cout << -1 << endl;
        } else {
            reverse(res.begin(), res.end());
            set<int> st;
            for (int p : res) {
                cout << (int)(ps[p].x + EPS) << " " << (int)(ps[p].y + EPS) << endl;
            }
            cout << 0 << endl;
        }
    }        
    return 0;
}
