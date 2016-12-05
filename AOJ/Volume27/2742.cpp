#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

constexpr double EPS = (1e-10);

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
};

double dot(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(const Point& a, const Point& b)
{
    return a.x * b.y - b.x * a.y;
}

double norm(const Point& p){
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
    Segment(const Point& s, const Point& t) : s{s}, t{t} {}
};

bool isIntersectSS(const Segment& a, const Segment& b)
{
    Point s[2] = {a.s, a.t}, t[2] = {b.s, b.t};
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) < 0 &&
            ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) < 0);
}

using Line = Segment;

bool isIntersectLL(const Line& a, const Line& b)
{
    return (abs(cross(a.t - a.s, b.t - b.s)) > EPS || 
            abs(cross(a.t - a.s, b.t - b.s)) < EPS);  
}

Point crosspointLL(const Line& a, const Line& b)
{
    using Vector = Point;
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

using Polygon = vector<Point>;
#define curr(G, i) (G[i % G.size()])
#define next(G, i) (G[(i + 1) % G.size()])

int get_score(const Point& cp, const vector<Point>& per,
              const vector<Polygon>& pgs)
{
    int score = 0;
    for (const auto& p : per) {
        Segment s1{p, cp};
        bool con = 0;
        for (const auto& pg : pgs) {
            for (int i = 0; i < (int)pg.size(); i++) {
                Segment s2{curr(pg, i), next(pg, i)};
                if (isIntersectSS(s1, s2)) {
                    con = 1;
                }
            }
        }
        if (!con) score++;
    }
    return score;
}

int get_num(int m1, int m2, const vector<Point>& per,
            int n1, int n2, const vector<Polygon>& pgs)
{
    int max_num = 0;
    for (const auto& p1 : pgs[n1]) {
        for (const auto& p2 : pgs[n2]) {
            Line l1{per[m1], p1}, l2{per[m2], p2};
            if (!isIntersectLL(l1, l2)) continue;
            auto cp = crosspointLL(l1, l2);

            max_num = max(max_num, get_score(cp, per, pgs));            
        }
    }
    return max_num;
}

int solve(const vector<Polygon>& pgs, const vector<Point>& per)
{
    int res = 1;
    int N = pgs.size(), M = per.size();
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = k; l < N; l++) {
                    res = max(res, get_num(i, j, per, k, l, pgs));
                }
            }
        }
    }
    return res;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<Polygon> pgs(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        pgs[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> pgs[i][j].x >> pgs[i][j].y;
        }
    }

    vector<Point> per(M);
    for (int i = 0; i < M; i++) {
        cin >> per[i].x >> per[i].y;
    }
    cout << solve(pgs, per) << endl;
    return 0;
}
