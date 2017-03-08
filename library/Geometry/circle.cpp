#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

constexpr double EPS = (1e-10);
constexpr double PI = acos(-1);
#define equals(a, b) (fabs(a - b) < EPS)
#define lt(a, b) (a - b < -EPS)
#define le(a, b) (lt(a, b) || equals(a, b))

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
};

Point operator * (const Point& a, const Point& b)
{
    return Point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
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

Point rotate(const Point& p, double th)
{
    return Point(cos(th) * p.x - sin(th) * p.y, sin(th) * p.x + cos(th) * p.y);
}

Point rotate90(const Point& p)
{
    return Point(-p.y, p.x);
}

istream& operator >> (istream& is, Point& p)
{ 
    return is >> p.x >> p.y;
}

ostream& operator << (ostream& os, Point& p)
{ 
    return os << "(" << p.x << "," << p.y << ")";
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
    if (cross(a,b) > EPS)  return COUNTER_CLOCKWISE;
    if (cross(a,b) < -EPS) return CLOCKWISE;
    if (dot(a,b) < -EPS)   return ONLINE_BACK;
    if (norm(a) < norm(b)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

struct Segment {
    Point s, t;
    Segment() {}
    Segment(Point s, Point t) : s{s}, t{t} {}
};

using Line = Segment;

Point projection(const Line& l, const Point& p)
{
    Vector b = l.t - l.s;
    double t = dot(p - l.s, b) / norm(b);
    return l.s + b * t;
}

double distance_LP(const Line& l, const Point& p)
{
    return abs(p - projection(l, p));
}

struct Circle {
    Point p;
    double r;
    Circle() {}
    Circle(Point p, double r) : p{p}, r{r} {}
};

bool intersect_CP(const Circle& c, const Point& p)
{
    return (abs(c.p - p) <= c.r + EPS);
}

bool intersect_CC(const Circle& a, const Circle& b)
{
    double d = abs(a.p - b.p);
    return (d <= a.r + b.r && d >= abs(a.r - b.r));
}

vector<Point> crosspoint_CC(const Circle& a, const Circle& b)
{
    vector<Point> res;
    double d = abs(a.p - b.p);
    if (!intersect_CC(a, b) || d < EPS) {
        return res;
    }
    double rc = (a.r * a.r - b.r * b.r + d * d) / (2.0 * d);
    double rs = sqrt(a.r * a.r - rc * rc);
    Point p = (b.p - a.p) / d;
    res.emplace_back(a.p + p * Point(rc, +rs));
    res.emplace_back(a.p + p * Point(rc, -rs));
    return res;
}

vector<Point> crosspoint_CL(const Circle& c, const Line& l)
{
    vector<Point> res;
    double d = distance_LP(l, c.p);
    if (le(d, c.r)) {
	Point p = projection(l, c.p);
	Vector v = (l.t - l.s) / abs(l.t - l.s);
	d = sqrt(c.r * c.r - d * d);
	res.emplace_back(p + v * d);
	res.emplace_back(p - v * d);
    }
    return res;
}

/*
  点pから引いた円の接点
 */
vector<Point> tangent_CP(const Circle& c, const Point& p)
{
    double x = norm(p - c.p);
    double d = x - c.r * c.r;
    if (d < -EPS) return vector<Point>();
    d = max(d, 0.0);
    Point p1 = (p - c.p) * (c.r * c.r / x);
    Point p2 = rotate90((p - c.p) * (-c.r * sqrt(d) / x));
    vector<Point> res;
    res.emplace_back(c.p + p1 - p2);
    res.emplace_back(c.p + p1 + p2);
    return res;
}

/*
  2円の共通接線を求める.
*/
vector<Line> tangent_CC(const Circle& a, const Circle& b)
{
    vector<Line> res;
    vector<Point> ps, qs;
    if (abs(b.p - a.p) < EPS) return res;
    if (abs(a.r - b.r) < EPS) {
	Point dir = b.p - a.p;
	dir = rotate90(dir * (a.r / abs(dir)));
	res.emplace_back(a.p + dir, b.p + dir);
	res.emplace_back(a.p - dir, b.p - dir);
    } else {
	Point p = a.p * (-b.r) + b.p * a.r;
	p = p * (1.0 / (a.r - b.r));
	ps = tangent_CP(a, p);
	qs = tangent_CP(b, p);
	int n = ps.size(), m = qs.size();
	for (int i = 0; i < min(n, m); i++) {
	    res.emplace_back(ps[i], qs[i]);
	}
    }
    Point p = a.p * b.r + b.p * a.r;
    p = p * (1.0 / (a.r + b.r));
    ps = tangent_CP(a, p);
    qs = tangent_CP(b, p);
    int n = ps.size(), m = qs.size();
    for (int i = 0; i < min(n, m); i++) {
	res.emplace_back(ps[i], qs[i]);
    }
    return res;
}

using Polygon = vector<Point>;
    
/*
  最小包含円
*/
Circle smallest_enclosing_circle(const Polygon& pg)
{
    Point p(0, 0);
    int N = pg.size();
    double d = 0.5;
    for (int i = 0; i < N; i++) {
	p = p + pg[i];
    }
    while (d > EPS) {
	for (int i = 0; i < 150; i++) {
	    int s = 0;
	    for (int j = 0; j < N; j++) {
		if (abs(pg[j] - p) > abs(pg[s] - p)) {
		    s = i;
		}
	    }
	    p = p + (pg[s] - p) * d;
	}
	d *= 0.5;
    }
    double r = 0;
    for (int i = 0; i < N; i++) {
	r = max(r, abs(pg[i] - p));
    }
    return Circle(p, r);
}
