#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (lt(a,b) || equal(a,b))
#define PI acos(-1)

struct Point{
    double x,y;

    Point(){}
    Point(double x,double y) : x(x),y(y) {}

    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k,y*k); }
    Point operator / (const double &k)const{ return Point(x/k,y/k); }
    bool operator < (const Point &p)const{ return x != p.x ? x < p.x : y < p.y; }
};

Point operator * (const Point &a,const Point &b){ return Point(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }

double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
Point rotate(const Point &p,double th){
    return Point(cos(th)*p.x-sin(th)*p.y,sin(th)*p.x+cos(th)*p.y);
}
Point rotate90(const Point &p){ return Point(-p.y,p.x); }

istream &operator >> (istream &is,Point &p){ 
    return is >> p.x >> p.y;
}

ostream &operator << (ostream &os,Point &p){ 
    return os << "(" << p.x << "," << p.y << ")";
}

#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
typedef Point Vector;

int ccw(Point p0,Point p1,Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b) > EPS){ return COUNTER_CLOCKWISE; }
    if(cross(a,b) < -EPS){ return CLOCKWISE; }
    if(dot(a,b) < -EPS){ return ONLINE_BACK; }
    if(norm(a) < norm(b)){ return ONLINE_FRONT; }
    return ON_SEGMENT;
}

struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};

struct Line{
    Point s,t;
    Line(){}
    Line(Point s,Point t) : s(s),t(t) {}
};

Point projection(const Line &l,const Point &p){
    Vector b = l.t-l.s;
    double t = dot(p-l.s,b)/norm(b);
    return l.s+b*t;
}

double distanceLP(const Line &l,const Point &p){
    return abs(p-projection(l,p));
}

struct Circle{
    Point p;
    double r;
    Circle(){}
    Circle(Point p,double r) : p(p),r(r) {}
};

bool isIntersectCC(const Circle &a,const Circle &b){
    double d = abs(a.p-b.p);
    return (d <= a.r+b.r && d >= abs(a.r-b.r));
}

vector<Point> crosspointCC(const Circle &a,const Circle &b){
    vector<Point> res;
    double d = abs(a.p-b.p);
    if(!isIntersectCC(a,b) || d < EPS){ return res; }
    double rc = (a.r*a.r-b.r*b.r+d*d)/(2.0*d);
    double rs = sqrt(a.r*a.r-rc*rc);
    Point p = (b.p-a.p)/d;
    res.push_back(Point(a.p+p*Point(rc,rs)));
    res.push_back(Point(a.p+p*Point(rc,-rs)));
    return res;
}

vector<Point> crosspointCL(const Circle &c,const Line &l){
    vector<Point> res;
    double d = distanceLP(l,c.p);
    if(le(d,c.r)){
	Point p = projection(l,c.p);
	Vector v = (l.t - l.s) / abs(l.t - l.s);
	d = sqrt(c.r*c.r-d*d);
	res.push_back(p + v*d);
	res.push_back(p - v*d);
    }
    return res;
}

/*
  点pから引いた円の接点
 */
vector<Point> tangentCP(const Circle &c,const Point &p){
    double x = norm(p - c.p);
    double d = x - c.r*c.r;
    if(d < -EPS) return vector<Point>();
    d = max(d, 0.0);
    Point p1 = (p-c.p)*(c.r*c.r/x);
    Point p2 = rotate90((p-c.p)*(-c.r*sqrt(d)/x));
    vector<Point> res;
    res.push_back(c.p + p1 - p2);
    res.push_back(c.p + p1 + p2);
    return res;
}

/*
  2円の共通接線を求める.
*/
vector<Line> tangentCC(const Circle &a,const Circle &b){
    vector<Line> res;
    vector<Point> ps,qs;
    if(abs(b.p-a.p) < EPS) return res;
    if(abs(a.r - b.r) < EPS){
	Point dir = b.p-a.p;
	dir = rotate90(dir*(a.r/abs(dir)));
	res.push_back(Line(a.p+dir,b.p+dir));
	res.push_back(Line(a.p-dir,b.p-dir));
    }else{
	Point p = a.p*(-b.r) + b.p*a.r;
	p = p*(1.0/(a.r-b.r));
	ps = tangentCP(a,p);
	qs = tangentCP(b,p);
	int n = ps.size(), m = qs.size();
	for(int i = 0 ; i < min(n,m) ; i++){
	    res.push_back(Line(ps[i],qs[i]));
	}
    }
    Point p = a.p*b.r + b.p*a.r;
    p = p*(1.0/(a.r+b.r));
    ps = tangentCP(a,p);
    qs = tangentCP(b,p);
    int n = ps.size(), m = qs.size();
    for(int i = 0 ; i < min(n,m) ; i++){
	res.push_back(Line(ps[i],qs[i]));
    }
    return res;
}
