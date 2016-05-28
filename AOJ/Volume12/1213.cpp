#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)

struct Point {
    double x, y;

    Point(){}
    Point(double x, double y) : x(x), y(y) {}

    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }    
    Point operator * (const double &k) const {
        return Point(x * k, y * k);
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

Line getPerpendicularBisector(const Point &a, const Point &b)
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

#define prev(G,i) (G[(i-1+G.size())%G.size()])
#define curr(G,i) (G[i%G.size()])
#define next(G,i) (G[(i+1)%G.size()])
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
        
double area(const Polygon &pg)
{
    double res = 0;
    for (int i = 0; i < (int)pg.size(); i++) {
        res += cross(pg[i], next(pg, i));
    }
    return abs(res)/2.0;
}

int tc;

bool voronoi()
{
    int N = 4, M = 3;

    Polygon pg(N);
    pg[0] = Point(    0,     0);
    pg[1] = Point(10000,     0);
    pg[2] = Point(10000, 10000);
    pg[3] = Point(    0, 10000);
    
    vector<Point> ps(M);
    for (int i = 0; i < M; i++) {
	cin >> ps[i].x >> ps[i].y;
    }

    if (ps[0].x == 0) return 0;
    
    Polygon p = pg;
    for (int i = 1; i < M; i++) {
        p = convex_cut(p, getPerpendicularBisector(ps[0], ps[i]));
    }    
    printf("%d %.15f\n", tc++, area(p)/100000000);
    return 1;
}

int main()
{
    tc = 1;
    while (voronoi()) {}       
    return 0;
}
