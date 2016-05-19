#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10

struct Point {
    double x, y;

    Point(){}
    Point(double x, double y) : x(x), y(y) {}
 
    Point operator + (const Point &p) const {  return Point(x + p.x, y + p.y); }
    Point operator - (const Point &p) const {  return Point(x - p.x, y - p.y); }
    Point operator * (const double &k) const { return Point(x * k, y * k); }
    Point operator / (const double &k) const { return Point(x / k, y / k); }
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

struct Segment {
    Point s, t;
    Segment(){}
    Segment(Point s, Point t) : s(s), t(t) {}
};

Point projection(const Segment &s, const Point &p)
{
    Vector b = s.t - s.s;
    double t = dot(p-s.s, b) / norm(b);
    return s.s + b*t;
}

bool isIntersectSP(const Segment &s, const Point &p)
{
    return (ccw(s.s, s.t, p) == 0);
}

double distanceSP(const Segment &s, const Point &p)
{
    Point r = projection(s, p);
    if(isIntersectSP(s, r)) return abs(r - p);
    return min(abs(s.s - p), abs(s.t - p));
}

int main()
{
    int N;
    double x, y;
    cin >> x >> y >> N;
    vector<Point> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    double res = 114514;
    for (int i = 0; i < N; i++) {
        int ni = (i + 1) % N;
        Segment s(p[i], p[ni]);
        res = min(res, distanceSP(s, Point(x, y)));
    }
    printf("%.10f\n", res);    
    return 0;
}
