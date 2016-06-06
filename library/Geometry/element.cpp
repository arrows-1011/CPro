#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (lt(a,b) || equal(a,b))
#define PI acos(-1)

struct Point {
    double x, y;

    Point(){}
    Point(double x, double y) : x(x), y(y) {}
 
    Point operator + (const Point &p) const {  return Point(x + p.x, y + p.y); }
    Point operator - (const Point &p) const {  return Point(x - p.x, y - p.y); }
    Point operator * (const double &k) const { return Point(x * k, y * k); }
    Point operator / (const double &k) const { return Point(x / k, y / k); }
    bool operator < (const Point &p) const {   return x != p.x ? x < p.x : y < p.y; }
    bool operator == (const Point &p) const {  return (x == p.x && y == p.y); }
};

double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b)
{
    return a.x * b.y - b.x * a.y;
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
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double toRad(double ang)
{
    return ang * PI / 180;
}

double toAng(double rad)
{
    return rad * 180 / PI;
}

/*
  これは,0°基準である。また,thはラジアン単位であることに注意が必要.

  ある点(x,y)を中心に回転する場合,
  Point(cos(th)*(p.x-x)-sin(th)*(p.y-y)+x,sin(th)*(p.x-x)+cos(th)*(p.y-y)+y);
  とする。
*/
Point rotate(const Point &p, double th)
{
    return Point(cos(th) * p.x - sin(th) * p.y, sin(th) * p.x + cos(th) * p.y);
}
Point rotate90(const Point &p)
{
    return Point(-p.y, p.x);
}

istream &operator >> (istream &is, Point &p)
{ 
    return is >> p.x >> p.y;
}

ostream &operator << (ostream &os, Point &p)
{ 
    return os << "(" << p.x << "," << p.y << ")";
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
    if(cross(a, b) > EPS)  return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS)   return ONLINE_BACK; // p2-p0-p1
    if(norm(a) < norm(b))  return ONLINE_FRONT; // p0-p1-p2
    return ON_SEGMENT; // p0-p2-p1
}

/* verified (AOJ 1033) */
double getAngle(const Point &a, const Point &b, const Point &c)
{
    Vector v1 = b-a, v2 = c-b;
    double aa = atan2(v1.y, v1.x),ba = atan2(v2.y, v2.x);
    if(aa > ba) swap(aa, ba);
    double ang = toAng(ba - aa);
    return min(ang, 360-ang);
}

struct Segment {
    Point s, t;
    Segment(){}
    Segment(Point s, Point t) : s(s), t(t) {}
};

typedef Segment Line;


// 法線ベクトルを求める(方向2つ)
vector<Vector> normal_line_vector(const Line &l)
{
    vector<Vector> vs;
    Vector v = l.t - l.s, p = v / abs(v);
    vs.push_back(Point(-p.y, p.x));
    vs.push_back(Point(p.y, p.x));
    return vs;
}

// 平行移動
vector<Line> translation(const Line &l, double d)
{
    vector<Vector> nlv = normal_line_vector(l);
    vector<Line> nl;
    nl.push_back(Line(l.s + nlv[0] * d, l.t + nlv[0] * d));
    nl.push_back(Line(l.s + nlv[1] * d, l.t + nlv[1] * d));
    return nl;
}

/*
  垂直二等分線を求める.
*/

Line getPerpendicularBisector(const Point &a, const Point &b)
{
    double cx = (a.x + b.x) / 2.0;
    double cy = (a.y + b.y) / 2.0;
    Point p = Point(cx + (a.y - b.y), cy + (b.x - a.x));
    return Line(Point(cx, cy),p);
}

Line getPerpendicularBisector(const Line &l)
{
    return getPerpendicularBisector(l.s, l.t);
}

/*
  線分上の点を列挙する。
  N分割する。
*/
vector<Point> getPointOnSegment(const Segment &s)
{
    Point p1 = s.s, p2 = s.t;
    vector<Point> res;
    const int N = 10;
    for (int i = 0; i <= N; i++) {
	double x = p1.x + i * (p2.x - p1.x) / N;
	double y = p1.y + i * (p2.y - p1.y) / N;
	Point np(x, y);
	res.push_back(np);
    }
    return res;
}

/* verified (AOJ Lib) */
Point projection(const Segment &s, const Point &p)
{
    Vector b = s.t - s.s;
    double t = dot(p-s.s, b) / norm(b);
    return s.s + b*t;
}

/* verified (AOJ Lib) */
Point reflection(const Segment &s, const Point &p)
{
    return p + (projection(s, p) - p)*2.0;
}

//交差判定
/* verified (AOJ Lib) */
bool isIntersectSS(const Segment &a, const Segment &b)
{
    Point s[2] = {a.s, a.t}, t[2] = {b.s, b.t};
    return (ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) <= 0 &&
	    ccw(t[0], t[1], s[0])*ccw(t[0], t[1], s[1]) <= 0);
}

/* verified (AOJ Lib) */
bool isIntersectSP(const Segment &s, const Point &p)
{
    return (ccw(s.s, s.t, p) == 0);
}

bool isIntersectLL(const Line &a, const Line &b)
{
    return (abs(cross(a.t - a.s, b.t - b.s)) > EPS || // 傾きが異なる
	    abs(cross(a.t - a.s, b.t - b.s)) < EPS);  // 同じ直線である
}

bool isIntersectLP(const Line &l, const Point &p)
{
    return (abs(ccw(l.s, l.t, p)) != 1);
}

bool isIntersectLS(const Line &l, const Segment &s)
{
    return (cross(l.t - l.s, s.s - l.s) * cross(l.t - l.s, s.t - l.s) < EPS);
}

//交点
/* verified (AOJ Lib) */
Point crosspointSS(const Segment &a, const Segment &b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

/* verified (AOJ Lib) */
Point crosspointLL(const Line &a, const Line &b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s+va*cross(vb, b.t - a.s) * (1.0 / d);
}

//距離
double distanceLP(const Line &l, const Point &p)
{
    return abs(p - projection(l, p));
}

double distanceLL(const Line &a, const Line &b)
{
    if (isIntersectLL(a, b)) return 0;
    return distanceLP(a, b.s);
}

double distanceLS(const Line &l, const Segment &s)
{
    if (isIntersectLS(l, s)) return 0;
    return min(distanceLP(l, s.s), distanceLP(l, s.t));
}

/* verified (AOJ Lib) */
double distanceSP(const Segment &s, const Point &p)
{
    Point r = projection(s, p);
    if(isIntersectSP(s, r)) return abs(r - p);
    return min(abs(s.s - p), abs(s.t - p));
}

/* verified (AOJ Lib) */
double distanceSS(const Segment a, const Segment b)
{
    if (isIntersectSS(a,b)) return 0;
    return min(min(distanceSP(a, b.s), distanceSP(a, b.t)),
	       min(distanceSP(b, a.s), distanceSP(b, a.t)));
}

// 線分の垂直判定
// verify(AOJ 0058)
bool isOrthogonalSS(const Segment &s1, const Segment &s2)
{
    Vector a = s1.t - s1.s;
    Vector b = s2.t - s2.s;
    return equal(dot(a, b), 0);
}

// 線分の平行判定
// verify(AOJ 0021)
bool isParallelSS(const Segment &s1, const Segment &s2)
{
    Vector a = s1.t - s1.s;
    Vector b = s2.t - s2.s;
    return equal(cross(a, b), 0);
}

/*
  heron
  3点から三角形の面積を求める.
*/
double getTriangleArea(const Point &a, const Point &b, const Point &c)
{
    double p = dist(a, b), q = dist(a, c), r = dist(b, c);
    double s = (p + q + r) / 2;
    return sqrt(s * (s-p) * (s-q) * (s-r));
}

//a -> long axis , b-> short axis 
double ellipse_area(double a, double b)
{
    return PI*a*b;
}

/*
  ここから線分アレンジメント
  verified (AOJ 1033)
*/
struct Edge {
    int to;
    double cost;
    Edge(int to, double cost) :
	to(to), cost(cost) {}
    bool operator < (const Edge &e)const
    {
	return lt(cost, e.cost);
    }
};

typedef vector<vector<Edge> > Graph;

/*
  線分アレンジメント
  重なる線分がないこと前提(
  equal(cross(a,b),0) (ベクトル同士のなす角が0°か180°)により取り除く.
  )
  各線分の端点と線分同士の交点を頂点とする.
  bool operator == (const Point &p)const{ return (x == p.x && y == p.y); } を書かないとエラーでる
*/

Graph segmentArrangement(vector<Segment> &segs, vector<Point> &ps)
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
	    if (equal(cross(a, b), 0)) {
                continue;
            }
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
	vector<pair<double,int> > vec;
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
