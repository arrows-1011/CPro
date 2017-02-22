#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

constexpr double EPS = (1e-10);
constexpr double INF = (1e55);
constexpr double PI = acos(-1);
#define equal(a, b) (fabs(a - b) < EPS)
#define lt(a, b) (a - b < -EPS)

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
    
    bool operator == (Point& p) const
    {
	if (equal(x, p.x) && equal(y, p.y)) {
	    return true;
	}
	return false;
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
    if (dot(a, b) < -EPS)   return ONLINE_BACK;
    if (norm(a) < norm(b))  return ONLINE_FRONT;
    return ON_SEGMENT;
}

/* 参照渡しをしてはいけない */
bool sortX(Point p1, Point p2){
    if(p1.x != p2.x){ 
	return (p1.x - p2.x < -EPS);
    }else{
	return (p1.y - p2.y < -EPS);
    }
}

/* 参照渡しをしてはいけない */
bool sortY(Point p1, Point p2)
{
    if (p1.y != p2.y) {
	return (p1.y - p2.y < -EPS);
    } else { 
	return (p1.x - p2.x < -EPS);
    }
}

struct Segment {
    Point s, t;
    
    Segment() {}
    Segment(Point s, Point t) : s{s}, t{t} {}
    
    bool operator == (Segment& seg) const
    {
	if (s == seg.s && t == seg.t) {
	    return true;
	}
	if (t == seg.s && s == seg.t) {
	    return true;
	}
	return false;
    }
};

using Line = Segment;

/*
  Polygonは反時計回りの順で与えられていること前提.
*/
using Polygon = vector<Point>;

/*
  最近点対を求める.
  
  verified
*/

bool compare_y(const Point& a, const Point& b)
{
    return a.y < b.y;
}

double closest_pair(Point* a, int n)
{
    if (n <= 1) return INF;
    int m = n / 2;
    double x = a[m].x;
    double d = min(closest_pair(a, m), closest_pair(a + m, n - m));
    inplace_merge(a, a + m, a + n, compare_y);

    Polygon b;
    for (int i = 0; i < n; i++) {
        if (fabs(a[i].x - x) >= d) continue;
        for(int j = 0; j < (int)b.size(); j++) {
            double dx = a[i].x - b[b.size()-j-1].x;
            double dy = a[i].y - b[b.size()-j-1].y;
            if (dy >= d) break;
            d = min(d,sqrt(dx * dx + dy * dy));
        }
        b.emplace_back(a[i]);
    }
    return d;
}

constexpr int MAX_N = 114514; // MAX_N is the number of Points

void solve_cp(){
    int N = MAX_N;
    Point p[MAX_N];
    printf("%.12f\n", closest_pair(p, N));
}

/*
  凸包を求める.
  凸包とは,点集合Pの全ての点を含む最小の凸多角形のこと.
  O(N log N)
  
  verified (AOJ Lib)
*/
Polygon convex_hull(Polygon &ps)
{
    int N = ps.size(), j = 0;
    Polygon pg(N * 2);
    sort(ps.begin(), ps.end(), sortY);
    for (int i = 0; i < N; i++) {
        while (j > 1 && cross(pg[j - 1] - pg[j - 2], ps[i] - pg[j - 1]) <= 0) {
            j--;
        }
        pg[j++] = ps[i];
    }
    int k = j;
    for (int i = N - 2; i >= 0; i--) {
        while (j > k && cross(pg[j - 1] - pg[j - 2], ps[i] - pg[j - 1]) <= 0) {
            j--;
        }
        pg[j++] = ps[i];
    }
    pg.resize(j - 1);
    return pg;
}

/*
  多角形の重心を求める。
  O(N)
*/
Point get_center_of_gravity(const Polygon& pg)
{
    int N = pg.size();
    Point p(0, 0);
    for (int i = 0; i < N; i++) {
	p = p + pg[i];
    }
    return p * (1.0 / N);
}

#define prev(G, i) (G[(i - 1 + G.size()) % G.size()])
#define curr(G, i) (G[i % G.size()])
#define next(G, i) (G[(i + 1) % G.size()])

/*
  凸多角形の直径を求める.
  (ただし凸多角形の直径とはその最遠頂点対間距離である.)
  O(N log N)
  verified (AOJ Lib)
  
*/
double polygon_diameter(Polygon& p)
{
    Polygon np = convex_hull(p);
    int N = np.size();
    if (N == 2) return dist(np[0], np[1]);
    int i = 0, j = 0;
    for (int k = 0; k < N; k++) {
	if (!sortX(np[i], np[k])) i = k;
	if (sortX(np[j], np[k]))  j = k;
    }
    double res = 0;
    int si = i, sj = j;
    while (i != sj || j != si) {
	res = max(res, dist(np[i], np[j]));
	Point p1 = next(np, i) - curr(np, i);
        Point p2 = next(np, j) - curr(np, j);
	if (cross(p1, p2) < 0) {
	    i = (i + 1) % N;
	} else {
	    j = (j + 1) % N;
	}
    }
    return res;
}

/*
  凸性判定
  O(N)
  ただし,Pointは反時計回りに与えられるものとする.
  verified (AOJ Lib)
*/

bool is_convex(const Polygon& p)
{
    for (int i = 0; i < (int)p.size(); i++) {
        if (ccw(prev(p, i), curr(p, i), next(p, i)) == CLOCKWISE) {
            return false; 
        }
    }
    return true;
}

/*
  多角形の面積を計算する.
  O(N)
  ただし,Pointは反時計回りに与えられるものとする.
  verified (AOJ Lib)
*/
double get_area(const Polygon& p)
{
    int N = p.size();
    double res = 0;
    for (int i = 1; i < N + 1; i++) {
	res += (p[i % N].x - p[i - 1].x) * (p[i % N].y + p[i - 1].y);
    }
    res /= 2.0;
    return abs(res);
}


/*
  単純多角形の面積を計算する
 */
double area(const Polygon& pg)
{
    double res = 0;
    for (int i = 0; i < (int)pg.size(); i++) {
	res += cross(pg[i], next(pg, i));
    }
    return abs(res) / 2.0;
}

Point crosspointLL(const Line& a, const Line& b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    if (abs(d) < EPS) return b.s;
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

/*
  凸多角形の切断.
  凸多角形を直線で切断し,その左側だけを残す.
  
  verified (AOJ Lib)
*/

Polygon convex_cut(const Polygon& pg, const Line& l)
{
    Polygon res;
    for (int i = 0; i < (int)pg.size(); i++) {
	Point cp = curr(pg, i), np = next(pg, i);
	if (ccw(l.s, l.t, cp) != -1) res.emplace_back(cp);
	if (ccw(l.s, l.t, cp) * ccw(l.s, l.t, np) < 0) {
	    res.emplace_back(crosspointLL(Line(cp, np), l));
	}
    }
    return res;
}

/*
  多角形-点の包含.
  多角形pgと点pについて,
  pがpgに含まれている場合->2
  pがpgの辺上にある場合->1
  それ以外の場合->0

  その点を通る半直線を引き，それが多角形の辺と何回交差するかを数える.
  一回交差するたびに内外が切り替わる.半直線としてx軸に平行で正の無限大方向に伸びるものを取れば,
  交差判定は y 座標の比較と外積の符号判定で行える.
  上の判定と同時に線上判定を行うことで境界判定も行う.
  
  O(N)
  
  多角形が反時計回りで与えられている必要がある.
  verified (AOJ Lib)
*/

int containPP(const Polygon& pg, const Point& p)
{
    int N = pg.size();
    bool in = false;
    for (int i = 0; i < N; i++) {
	Point a = curr(pg, i) - p, b = next(pg, i) - p;
	if (a.y > b.y) swap(a, b);
	if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
	if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
    }
    return (in ? 2 : 0); 
}

/*
  ここから多角形-線分の内包判定
*/

struct Data {
    Point p;
    double d;
    Data(Point p, double d) : p{p}, d{d} {}
    bool operator < (const Data& data) const
    {
	if (!equal(d, data.d)) {
	    return lt(d, data.d);
	} else {
	    return p < data.p;
	}
    }
};

bool isIntersectSS(const Segment& a, const Segment& b)
{
    Point s[2] = {a.s, a.t}, t[2] = {b.s, b.t};
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
            ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}
 
Point crosspointSS(const Segment& a, const Segment& b)
{
    Vector va = a.t - a.s, vb = b.t - b.s;
    double d = cross(vb, va);
    return a.s + va * cross(vb, b.t - a.s) * (1.0 / d);
}

/*
  (非凸)多角形-線分の内包判定
  
  about
  http://d.hatena.ne.jp/kanetai/20120711/1342005754
  verified (AOJ 2514)
*/

bool containPS(const Polygon& pg, Segment& s)
{
    vector<Data> v;
    v.emplace_back(s.s, 0);
    v.emplace_back(s.t,dist(s.s, s.t));
    set<Point> st;
    for (int i = 0; i < (int)pg.size(); i++) {
	Segment seg(curr(pg, i), next(pg, i));
	if (seg == s) return true;
	if (ccw(seg.s, seg.t, s.s) == 0 && ccw(seg.s, seg.t, s.t) == 0) {
	    return true;
	}
 
	if (isIntersectSS(s, seg)) {
	    Point cp = crosspointSS(s, seg);
	    double d = dist(cp, s.s);
	    if (st.find(cp) != st.end()) {
		continue;
	    }
	    st.insert(cp);
	    v.emplace_back(cp, d);
	}
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size()-1; i++) {
	Point cp = (v[i].p + v[i+1].p) / 2.0;
	if (containPP(pg, cp) == 0) {
	    return false;
	}
    }
    return true;
}
