#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = 1e-8;

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
        return (x == p.x && y == p.y);
    }
};


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

constexpr int COUNTER_CLOCKWISE = +1;
constexpr int CLOCKWISE         = -1;
constexpr int ONLINE_BACK       = +2;
constexpr int ONLINE_FRONT      = -2;
constexpr int ON_SEGMENT        = +0;
using Vector = Point;

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

Point proj(const Segment& s, const Point& p)
{
    Vector b = s.t - s.s;
    double t = dot(p - s.s, b) / norm(b);
    return s.s + b * t;
}

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

double distance_SP(const Segment& s, const Point& p)
{
    Point r = proj(s, p);
    if (intersect_SP(s, r)) return abs(r - p);
    return min(abs(s.s - p), abs(s.t - p));
}

double distance_SS(const Segment& a, const Segment& b)
{
    if (intersect_SS(a, b)) return 0;
    return min(min(distance_SP(a, b.s), distance_SP(a, b.t)),
               min(distance_SP(b, a.s), distance_SP(b, a.t)));
}

int main()
{
    int W, N;
    while (cin >> W >> N, W > 0) {
        vector<vector<Point>> v(N + 2);
        vector<int> size(N + 2);
        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            vector<Point> ps(M);
            for (int j = 0; j < M; j++) {
                cin >> ps[j].x >> ps[j].y;
            }
            v[i] = ps;
            size[i] = ps.size();
        }

        constexpr double MAX = 10000;
        constexpr double INF = 1LL << 55;
        
        v[N] = {{0, 0}, {0, MAX}};
        v[N + 1] = {{(double)W, 0}, {(double)W, MAX}};
        size[N] = size[N + 1] = 2;
        
        vector<vector<double>> di(N + 2, vector<double>(N + 2, INF));
        for (int i = 0; i < N + 2; i++) {
            for (int j = 0; j < N + 2; j++) {
                if (i == j) continue;
                for (int k = 0; k < size[i]; k++) {
                    for (int l = 0; l < size[j]; l++) {
                        Segment s1{v[i][k], v[i][(k + 1) % size[i]]};                    
                        Segment s2{v[j][l], v[j][(l + 1) % size[j]]};

                        di[i][j] = min(di[i][j], distance_SS(s1, s2));
                    }
                }
            }
        }

        using P = pair<double, int>;               
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push(P{0, N});

        vector<double> d(N + 2, INF);
        d[N] = 0;
                
        while (!pq.empty()) {
            double c;
            int v;
            tie(c, v) = pq.top(); pq.pop();

            if (d[v] < c) continue;
            
            if (v == N + 1) {
                printf("%.15f\n", d[v]);
                break;
            }

            for (int i = 0; i < N + 2; i++) {
                if (v == i) continue;
                if (d[v] + di[v][i] < d[i]) {
                    d[i] = d[v] + di[v][i];
                    pq.push(P{d[i], i});
                }
            }
        }
    }        
    return 0;
}
