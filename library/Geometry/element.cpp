#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

constexpr double EPS = (1e-10);
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

double dist(const Point& a, const Point& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double to_rad(double ang)
{
    return ang * PI / 180;
}

double to_ang(double rad)
{
    return rad * 180 / PI;
}

/*
  これは,0°基準である。また,thはラジアン単位であることに注意が必要.

  ある点(x,y)を中心に回転する場合,
  Point(cos(th) * (p.x - x) - sin(th) * (p.y - y) + x,
        sin(th) * (p.x - x) + cos(th) * (p.y - y) + y);
  とする。
*/
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
    if (cross(a, b) > EPS)  return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS)   return ONLINE_BACK;  // p2-p0-p1
    if (norm(a) < norm(b))  return ONLINE_FRONT; // p0-p1-p2
    return ON_SEGMENT;                          // p0-p2-p1
}

/* verified (AOJ 1033) */
double get_angle(const Point& a, const Point& b, const Point& c)
{
    Vector v1 = b - a, v2 = c - b;
    double aa = atan2(v1.y, v1.x), ba = atan2(v2.y, v2.x);
    if (aa > ba) swap(aa, ba);
    double ang = to_ang(ba - aa);
    return min(ang, 360 - ang);
}

struct Segment {
    Point s, t;
    Segment() {}
    Segment(Point s, Point t) : s{s}, t{t} {}
};

using Line = Segment;

// 法線ベクトルを求める(方向2つ)
vector<Vector> normal_line_vector(const Line& l)
{
    vector<Vector> vs;
    Vector v = l.t - l.s, p = v / abs(v);
    vs.emplace_back(-p.y, p.x);
    vs.emplace_back(p.y, p.x);
    return vs;
}

// 平行移動
vector<Line> translation(const Line& l, double d)
{
    vector<Vector> nlv = normal_line_vector(l);
    vector<Line> nl;
    nl.emplace_back(l.s + nlv[0] * d, l.t + nlv[0] * d);
    nl.emplace_back(l.s + nlv[1] * d, l.t + nlv[1] * d);
    return nl;
}

/*
  垂直二等分線を求める.
*/

Line get_perpendicularBisector(const Point& a, const Point& b)
{
    double cx = (a.x + b.x) / 2.0;
    double cy = (a.y + b.y) / 2.0;
    Point p = Point(cx + (a.y - b.y), cy + (b.x - a.x));
    return Line(Point(cx, cy),p);
}

Line get_perpendicularBisector(const Line& l)
{
    return get_perpendicularBisector(l.s, l.t);
}

/*
  線分上の点を列挙する。
  N分割する。
*/
vector<Point> get_point_on_segment(const Segment& s)
{
    Point p1 = s.s, p2 = s.t;
    vector<Point> res;
    const int N = 10;
    for (int i = 0; i <= N; i++) {
	double x = p1.x + i * (p2.x - p1.x) / N;
	double y = p1.y + i * (p2.y - p1.y) / N;
	Point np(x, y);
	res.emplace_back(np);
    }
    return res;
}

/* verified (AOJ Lib) */
Point projection(const Segment& s, const Point& p)
{
    Vector b = s.t - s.s;
    double t = dot(p - s.s, b) / norm(b);
    return s.s + b * t;
}

/* verified (AOJ Lib) */
Point reflection(const Segment& s, const Point& p)
{
    return p + (projection(s, p) - p) * 2.0;
}

//交差判定
/* verified (AOJ Lib) */
bool intersect_SS(const Segment& a, const Segment& b)
{
    Point s[2] = {a.s, a.t}, t[2] = {b.s, b.t};
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
	    ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}

/* verified (AOJ Lib) */
bool intersect_SP(const Segment& s, const Point& p)
{
    return (ccw(s.s, s.t, p) == 0);
}

bool intersect_LL(const Line& a, const Line& b)
{
    return (abs(cross(a.t - a.s, b.t - b.s)) > EPS || // 傾きが異なる
	    abs(cross(a.t - a.s, b.t - b.s)) < EPS);  // 同じ直線である
}

bool intersect_LP(const Line& l, const Point& p)
{
    return (abs(ccw(l.s, l.t, p)) != 1);
}

bool intersect_LS(const Line& l, const Segment& s)
{
    return (cross(l.t - l.s, s.s - l.s) * cross(l.t - l.s, s.t - l.s) < EPS);
}

//交点
/* verified (AOJ Lib) */
Point crosspoint_SS(const Segment& a, const Segment& b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

/* verified (AOJ Lib) */
Point crosspoint_LL(const Line& a, const Line& b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

//距離
double distance_LP(const Line& l, const Point& p)
{
    return abs(p - projection(l, p));
}

double distance_LL(const Line& a, const Line& b)
{
    if (intersect_LL(a, b)) return 0;
    return distance_LP(a, b.s);
}

double distance_LS(const Line& l, const Segment& s)
{
    if (intersect_LS(l, s)) return 0;
    return min(distance_LP(l, s.s), distance_LP(l, s.t));
}

/* verified (AOJ Lib) */
double distance_SP(const Segment& s, const Point& p)
{
    Point r = projection(s, p);
    if (intersect_SP(s, r)) return abs(r - p);
    return min(abs(s.s - p), abs(s.t - p));
}

/* verified (AOJ Lib) */
double distance_SS(const Segment& a, const Segment& b)
{
    if (intersect_SS(a, b)) return 0;
    return min(min(distance_SP(a, b.s), distance_SP(a, b.t)),
	       min(distance_SP(b, a.s), distance_SP(b, a.t)));
}

// 線分の垂直判定
// verify(AOJ 0058)
bool orthogonal_SS(const Segment& s1, const Segment& s2)
{
    Vector a = s1.t - s1.s;
    Vector b = s2.t - s2.s;
    return equals(dot(a, b), 0);
}

// 線分の平行判定
// verify(AOJ 0021)
bool parallel_SS(const Segment& s1, const Segment& s2)
{
    Vector a = s1.t - s1.s;
    Vector b = s2.t - s2.s;
    return equals(cross(a, b), 0);
}

/*
  heron
  3点から三角形の面積を求める.
*/
double get_triangle_area(const Point& a, const Point& b, const Point& c)
{
    double p = dist(a, b), q = dist(a, c), r = dist(b, c);
    double s = (p + q + r) / 2;
    return sqrt(s * (s - p) * (s - q) * (s - r));
}

//a -> long axis , b-> short axis 
double ellipse_area(double a, double b)
{
    return PI * a * b;
}

/*
  ここから線分アレンジメント
  verified (AOJ 1033)
*/
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

/*
  線分アレンジメント
  重なる線分がないこと前提(
  equals(cross(a,b),0) (ベクトル同士のなす角が0°か180°)により取り除く.
  )
  各線分の端点と線分同士の交点を頂点とする.
  bool operator == (const Point &p)const{ return (x == p.x && y == p.y); } を書かないとエラーでる
*/

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
