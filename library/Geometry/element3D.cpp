#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (lt(a,b) || equal(a,b))

struct Point3D{
    Point3D(){}
    Point3D(double x,double y,double z) : x(x),y(y),z(z) {}
  
    Point3D operator + (const Point3D &p)const{ return Point3D(x+p.x,y+p.y,z+p.z); }
    Point3D operator - (const Point3D &p)const{ return Point3D(x-p.x,y-p.y,z-p.z); }
    Point3D operator * (double k)const{ return Point3D(x*k,y*k,z*k); }
    Point3D operator / (double k)const{ return Point3D(x/k,y/k,z/k); }
    double x,y,z;
};

double dot(const Point3D &a,const Point3D &b){ return a.x*b.x + a.y*b.y + a.z*b.z; }
double norm(const Point3D &p){ return dot(p,p); }
double abs(const Point3D &p){ return sqrt(norm(p)); }
double cross(const Point3D &a,const Point3D &b){
    return abs(Point3D(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}

istream &operator >> (istream &is,Point3D &p){
    return is >> p.x >> p.y >> p.z;
}

class Line{
public:
    Line(){}
    Line(Point3D s,Point3D t) : s(s), t(t) {}
    Point3D s,t;
};

typedef Line Segment;

Point3D projection(const Line &l,const Point3D &p){
    Point3D b = l.t - l.s;
    double t = dot(p-l.s,b)/norm(b);
    return l.s + b*t;
}

double distanceLP(const Line &l,const Point3D &p){
    return abs(p-projection(l,p));
}

class Sphere{
public:
    Sphere(){}
    Sphere(Point3D p,double r) : p(p), r(r) {}
    Point3D p;
    double r;
};

#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
typedef Point3D Vector;
 
int ccw(Point3D p0,Point3D p1,Point3D p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(abs(cross(a,b)) > EPS){ return COUNTER_CLOCKWISE; }
    if(abs(cross(a,b)) < -EPS){ return CLOCKWISE; }
    if(dot(a,b) < -EPS){ return ONLINE_BACK; }
    if(norm(a) < norm(b)){ return ONLINE_FRONT; }
    return ON_SEGMENT;
}

/*
  vecが球と直線の交点
*/
bool isIntersectSL(const Sphere &c,const Line &l){
    vector<Point3D> vec;
    double d = distanceLP(l,c.p);
    if(le(d,c.r)){
	Point3D p = projection(l,c.p);
	Point3D v = (l.t - l.s) / abs(l.t - l.s);
	d = sqrt(c.r*c.r-d*d);
	vec.push_back(p - v*d);
	vec.push_back(p + v*d);
	for(int i = 0 ; i < (int)vec.size() ; i++){
	    if(ccw(l.s,l.t,vec[i]) == ON_SEGMENT){
		return true;
	    }
	}
    }
    return false;
}
