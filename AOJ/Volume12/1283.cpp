#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10

struct Point {
    double x, y;

    Point(){}
    Point(double x, double y) : x(x), y(y) {}
 
    Point operator + (const Point &p)const{ return Point(x+p.x, y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x, y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k, y*k); }
    Point operator / (const double &k)const{ return Point(x/k, y/k); }
};

double dot(const Point &a, const Point &b)
{
    return a.x*b.x + a.y*b.y;
}

double cross(const Point &a, const Point &b)
{
    return a.x*b.y - b.x*a.y;
}

double norm(const Point &p){
    return dot(p, p);
}

double abs(const Point &p)
{
    return sqrt(norm(p));
}

double dist(const Point &a, const Point &b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

typedef Point Vector;

int ccw(const Point &p0, const Point &p1, const Point &p2)
{
    Vector a = p1 - p0, b = p2 - p0;
    if (cross(a, b) > EPS)  return +1;
    if (cross(a, b) < -EPS) return -1;
    if (dot(a, b) < -EPS)   return +2; 
    if (norm(a) < norm(b))  return -2;
    return +0;
}

struct Segment {
    Point s, t;
    Segment(){}
    Segment(Point s, Point t) : s(s), t(t) {}
};

#define curr(G,i) (G[i%G.size()])
#define next(G,i) (G[(i+1)%G.size()])
typedef vector<Point> Polygon;
typedef Segment Line;

Point crosspointLL(const Line &a, const Line &b)
{
    Vector va = a.t-a.s, vb = b.t-b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

Polygon convex_cut(const Polygon &pg, const Line &l)
{
    Polygon res;
    for (int i = 0; i < (int)pg.size(); i++) {
	Point cp = curr(pg,i), np = next(pg,i);
	if (ccw(l.s, l.t, cp) != -1) res.push_back(cp);
	if (ccw(l.s, l.t, cp)*ccw(l.s, l.t, np) < 0) {
	    res.push_back(crosspointLL(Line(cp, np), l));
	}
    }
    return res;
}

vector<Vector> normal_line_vector(const Line &l)
{
    vector<Vector> vs;
    Vector v = l.t - l.s, p = v / abs(v);
    vs.push_back(Point(-p.y, p.x));
    vs.push_back(Point(p.y, p.x));
    return vs;
}

vector<Line> translation(const Line &l, double d)
{
    vector<Vector> nlv = normal_line_vector(l);
    vector<Line> nl;
    nl.push_back(Line(l.s + nlv[0]*d, l.t + nlv[0]*d));
    nl.push_back(Line(l.s + nlv[1]*d, l.t + nlv[1]*d));
    return nl;
}

bool c(double d, const Polygon &pg)
{
    Polygon p = pg;
    for (int i = 0; i < (int)pg.size(); i++) {
        Line l(curr(pg, i), next(pg, i)), ll;
        vector<Line> nl = translation(l, d);
        ll = (ccw(l.s, l.t, nl[0].s) == 1 ? nl[0] : nl[1]);
        p = convex_cut(p, ll);
    }
    return (p.size() > 0);
}

int main()
{
    int n;
    while (cin >> n, n) {
        Polygon pg(n);
        for (int i = 0; i < n; i++) {
            cin >> pg[i].x >> pg[i].y;
        }

        double l = 0, r = 10000;
        for (int i = 0; i < 150; i++) {
            double mid = (l + r) / 2;
            if (c(mid, pg)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%.8f\n", r);
    }
    return 0;
}
