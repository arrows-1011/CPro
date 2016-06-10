#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-7
 
class Point {
  public:
    double x, y;
    Point (double x = 0.0, double y = 0.0) : x(x),y(y) {}
    Point operator + (Point p) {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator - (Point p) {
        return Point(x - p.x, y - p.y);
    }
    
    Point operator * (double a) {
        return Point(x * a, y * a);
    }
    
    Point operator / (double a) {
        return Point(x / a, y / a);
    }
    double abs() {
        return sqrt(norm());
    }
    double norm() {
        return x * x + y * y;
    }
};

double dot(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}
 
class Segment {
  public:
    Point t, s;
    Segment(Point t, Point s) : t(t), s(s) {}
    Point projection(Point &p) {
	Point b = s - t;
	double d = dot(p-t,b) / b.norm();
	return t + b*d;
    }
};
 
class Circle {
  public:
    double x, y, r;
    Circle(double x = 0.0, double y = 0.0, double r = 0.0) :
        x(x), y(y), r(r) {}
};
 
int N;
Point t, s;
Circle ci[300];
 
bool check(Point p0, Point p1, Point p2)
{
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (cross(a,b) > EPS) return 0;
    if (cross(a,b) < -EPS) return 0;
    if (dot(a,b) < -EPS) return 0;
    if (a.norm() < b.norm()) return 0;
    return 1;
}
 
bool getStateCS(Circle c, Segment seg)
{
    Point cp = Point(c.x, c.y);
    Point p = seg.projection(cp);
    Point pp = p - cp;
 
 
    Point a = seg.t - cp;
    Point b = seg.s - cp;
     
    if((a.abs() > c.r && b.abs() < c.r) ||
       (a.abs() < c.r && b.abs() > c.r) ) return 1;
    if(a.abs() > c.r && b.abs() > c.r){
	if(pp.abs()-EPS < c.r && check(seg.t, seg.s,p)){
	    return 1;
	}
    }
    return 0;
}
 
bool judge()
{
    Segment seg = Segment(t, s);
 
    for (int i = 0; i < N; i++) {
	if (getStateCS(ci[i], seg)) return 1;
    }
    return 0;
}
 
int main()
{
    int M;
    while (cin >> N, N) {
	for (int i = 0; i < N; i++) {
	    cin >> ci[i].x >> ci[i].y >> ci[i].r;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
	    cin >> t.x >> t.y >> s.x >> s.y; 
	    if (judge()) {
		cout << "Safe" << endl;
	    } else {
		cout << "Danger" << endl;
	    }
	}
    }
    return 0;
}
