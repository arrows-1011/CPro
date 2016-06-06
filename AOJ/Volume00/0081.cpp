#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
 
class Point {
public:
    double x, y;
 
    Point(double x = 0, double y = 0) : x(x), y(y) {}
 
    Point operator + (Point p)
    {
	return Point(x + p.x, y + p.y);
    }
 
    Point operator - (Point p)
    {
	return Point(x - p.x, y - p.y);
    }
 
    Point operator * (double k)
    {
	return Point(x * k, y * k);
    }
 
    double norm()
    {
	return x * x + y * y;
    }
};
 
struct Segment {
    Point p1, p2;
};
 
typedef Point Vector;
 
double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}
 
Point project(Segment s, Point p)
{
    Vector base = s.p2 - s.p1;
    double t = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * t;
}
 
Point reflect(Segment s, Point p)
{
    return p + (project(s, p) - p) * 2.0;
}
 
int main()
{
    Point p1, p2, q;
 
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf"
		,&p1.x ,&p1.y, &p2.x ,&p2.y ,&q.x ,&q.y) != EOF) {
 
	Segment s = {p1, p2};
	Point p = reflect(s, q);
 
	printf("%.6f %.6f\n", p.x, p.y);
    }
    return 0;
}
