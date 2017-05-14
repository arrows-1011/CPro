#include <bits/stdc++.h>
  
using namespace std;
  
#define EPS (1e-10)
  
struct Point {
    double x, y;
  
    Point() {}
    Point (double x, double y) : x(x), y(y) {}
  
    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
      
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
      
    Point operator * (const double &k) const {
        return Point(x * k, y * k);
    }
  
    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
  
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
  
double norm(const Point &p)
{
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
  
bool sortY(Point p1, Point p2)
{
    if (p1.y != p2.y) {
    return (p1.y - p2.y < -EPS);
    } else { 
    return (p1.x - p2.x < -EPS);
    }
}
  
typedef vector<Point> Polygon;
  
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
  
void insert(set<Point> &points, Point p)
{
    const int dx[] = {-1, -1, +1, +1};
    const int dy[] = {-1, +1, +1, -1};
  
    for (int i = 0; i < 4; i++) {
        double nx = p.x + dx[i] / 2.0;
        double ny = p.y + dy[i] / 2.0;
        points.insert(Point(nx, ny));
    }   
}
  
struct Segment {
    Point s, t;
    Segment () {}
    Segment (Point s, Point t) : s(s), t(t) {}
};
  
typedef Segment Line;
  
Point projection(const Segment &s, const Point &p)
{
    Vector b = s.t - s.s;
    double t = dot(p - s.s, b) / norm(b);
    return s.s + b * t;
}
  
double distanceLP(const Line &l, const Point &p)
{
    return abs(p - projection(l, p));
}
  
int main()
{
    int N;
    cin >> N;
      
    set<Point> points;
    insert(points, Point(0, 0));
      
    vector<Point> p(N);
    p[0] = Point(0, 0);
  
    const int dx[] = {-1, +0, +1, +0};
    const int dy[] = {+0, +1, +0, -1};
      
    for (int i = 0; i < N - 1; i++) {
        int n, d;
        cin >> n >> d;
        p[i + 1] = Point(p[n].x + dx[d], p[n].y + dy[d]);
        insert(points, p[i + 1]);
    }
      
    Polygon pg;
    for (auto &point: points) {
        pg.push_back(point);
    }
    pg = convex_hull(pg);
    N = pg.size();
    double res = 1e55;    
    for (int i = 0; i < N; i++) {
        int ci = i, ni = (i + 1) % N;
        Line l1(pg[ci], pg[ni]);
          
        int jj = -1;
        double h = 0;
        for (int j = 0; j < N; j++) {
            double d = distanceLP(l1, pg[j]);
            if (d > h) {
                h = d;
                jj = j;
            }
        }
        Point pp = projection(l1, pg[jj]);               
        Line l2(pp, pg[jj]);
  
        if (pp == pg[jj]) continue;
          
        jj = -1;
        double w1 = 0;
        for (int j = 0; j < N; j++) {
            double d = distanceLP(l2, pg[j]);
            if (d > w1) {
                w1 = d;
                jj = j;
            }
        }
        Point pp2 = projection(l1, pg[jj]);
        Line l3(pp2, pg[jj]);
  
        if (pp2 == pg[jj]) continue;
          
        double w = 0;        
        for (int j = 0; j < N; j++) {
            double d = distanceLP(l3, pg[j]);
            if (d > w) w = d;
        }        
        res = min(res, h * w);
    }
    printf("%.10f\n", res);
    return 0;
}
