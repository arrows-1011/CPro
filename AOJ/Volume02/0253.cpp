#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-9
 
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y){}
   
    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
   
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
 
    Point operator * (const double k) const {
        return Point(x * k, y * k);
    }
 
    Point operator / (const double k) const {
        return Point(x / k, y / k);
    }
};
 
typedef Point Vector;
 
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
 
struct Line {
    Point s, t;
    Line(){}
    Line(Point s, Point t) : s(s), t(t) {}
};
 
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
    nl.push_back(Line(l.t + nlv[0] * d, l.s + nlv[0] * d));
    nl.push_back(Line(l.t + nlv[1] * d, l.s + nlv[1] * d));
    return nl;
}

int ccw(const Point &p0, const Point &p1, const Point &p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)  return +1;
    if (cross(a, b) < -EPS) return -1;
    if (dot(a, b) < -EPS)   return +2;
    if (norm(a) < norm(b))  return -2;
    return +0;
}

Point crosspointLL(const Line &a, const Line &b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}
 
typedef vector<Point> Polygon;
#define curr(G, i) (G[i%G.size()])
#define next(G, i) (G[(i+1)%G.size()])
 
Polygon convex_cut(const Polygon &pg, const Line &l)
{
    Polygon res;
    for (int i = 0; i < (int)pg.size(); i++) {
	Point cp = curr(pg,i), np = next(pg,i);
	if(ccw(l.s, l.t, cp) != -1) res.push_back(cp);
	if(ccw(l.s, l.t, cp) * ccw(l.s, l.t, np) < 0){
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
    return abs(res) / 2.0;
}
 
double calc(Polygon &pg, double d, Line &l, double V)
{
    double lb = 0, ub = 25252;
    for (int i = 0; i < 150; i++) {
        double h = (lb + ub) / 2;
        vector<Line> vl = translation(l, h);
        Line nl = (ccw(l.s, l.t, vl[0].s) == 1 ? vl[0] : vl[1]);       
        Polygon npg = convex_cut(pg, nl);
        double v = d * area(npg);
        if (v < V) {
            lb = h;
        } else {
            ub = h;
        }
    }
    return lb;
}

double solve(Polygon &pg, double d, double V)
{
    int n = pg.size();
    double max_height = 0;
    for (int i = 0; i < n; i++) {
        Line l(curr(pg, i), next(pg, i));
        max_height = max(max_height, calc(pg, d, l, V));
    }
    return max_height;
}
 
int main()
{
    int n;
    double d, V;
    while (cin >> n >> d >> V, n) {
        Polygon pg(n);
        for (int i = 0; i < n; i++) {
            cin >> pg[i].x >> pg[i].y;
        }
        printf("%.10f\n", solve(pg, d, V));
    }
    return 0;
}
