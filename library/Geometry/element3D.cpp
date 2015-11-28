#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (lt(a,b) || equal(a,b))
#define INF (1LL<<55)
#define PI acos(-1)

struct Point3D{
    double x,y,z;
    Point3D(){}
    Point3D(double x,double y,double z) : x(x),y(y),z(z) {}
  
    Point3D operator + (const Point3D &p)const{ return Point3D(x+p.x,y+p.y,z+p.z); }
    Point3D operator - (const Point3D &p)const{ return Point3D(x-p.x,y-p.y,z-p.z); }
    Point3D operator * (double k)const{ return Point3D(x*k,y*k,z*k); }
    Point3D operator / (double k)const{ return Point3D(x/k,y/k,z/k); }
};

double dot(const Point3D &a,const Point3D &b){ return a.x*b.x + a.y*b.y + a.z*b.z; }
double norm(const Point3D &p){ return dot(p,p); }
double norm(const Point3D &a,const Point3D &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}
double abs(const Point3D &p){ return sqrt(norm(p)); }
double cross(const Point3D &a,const Point3D &b){
    return abs(Point3D(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
Point3D crossVec(const Point3D &a,const Point3D &b){
    return Point3D(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}
double distancePP(const Point3D &a,const Point3D &b){
    return abs(a-b);
}

istream &operator >> (istream &is,Point3D &p){
    return is >> p.x >> p.y >> p.z;
}

struct Segment{
    Point3D s,t;
    Segment(){}
    Segment(Point3D s,Point3D t) : s(s), t(t) {}
};

typedef Segment Line;

Point3D projection(const Line &l,const Point3D &p){
    Point3D b = l.t - l.s;
    double t = dot(p-l.s,b)/norm(b);
    return l.s + b*t;
}

double distanceLP(const Line &l,const Point3D &p){
    return abs(p - projection(l,p));
}

double distanceLL(const Line &a,const Line &b){
    Point3D v = crossVec(a.t-a.s, b.t-b.s);
    Point3D p = a.s - b.s;
    if(abs(v) < EPS) return distanceLP(a,b.s);
    return abs(dot(v,p))/abs(v);
}

/*
  線分と点の距離
 */
double distanceSP(const Segment &s,const Point3D &p){
    double a = dot(s.t-s.s, s.t-s.s);
    double b = dot(s.t-s.s, s.s-p);
    double c = dot(s.s-p, s.s-p);
    double t = -b/a;
    if(t < 0) return abs(s.s - p);
    if(t > 1) return abs(s.t - p);
    return a * t * t + 2 * b * t + c;
}

double distanceSS(const Segment &s1,const Segment &s2){
    // a*s + b*t = e
    // c*s + d*t = f
    Point3D v1 = s1.t-s1.s,v2 = s2.t-s2.s,v3 = s1.s-s2.s;
    double a = dot(v1,v1);
    double b = -dot(v1,v2);
    double c = -dot(v1,v2);
    double d = dot(v2,v2);
    double e = -dot(v1,v3);
    double f = dot(v2,v3);
   
    double ans = INF;
    ans = min(ans,distanceSP(s1,s2.s));
    ans = min(ans,distanceSP(s1,s2.t));
    ans = min(ans,distanceSP(s2,s1.s));
    ans = min(ans,distanceSP(s2,s1.t));
 
    double det = a*d-b*c;
    if(det != 0){
	double s = (d*e - b*f) / det;
	double t = (-c*e + a*f) / det;
	if(0 <= s && s <= 1 && 0 <= t && t <= 1){
	    ans = min(ans, distancePP(s1.s+v1*s, s2.s+v2*t));
	}
    }
    return ans;
}

/*
  極座標（半径,緯度,経度）から直交座標（x,y,z）を求める
  ラジアン注意
  未確認、wikipediaより引用
 */
Point3D getP3(double r,double ido,double keido){
    Point3D res;
    res.x = r * sin(ido) * cos(keido);
    res.y = r * sin(ido) * sin(keido);
    res.z = r * cos(ido);
    return res;
}

/*
  球面上にある二点間の球面距離
  ラジアン注意
*/
double gcdist(double r, double ido1, double keido1, double ido2, double keido2){
    double s = sin((ido1-ido2) / 2.0), t = sin((keido1-keido2) / 2.0);
    return 2.0 * r * asin(sqrt(max(0.0, s*s+cos(ido1)*cos(ido2)*t*t)));
}

/*
  球面上にある二点間の直線距離
  ラジアン注意
 */
double gcchord(double r, double ido1, double keido1, double ido2, double keido2){
    double c11 = cos(ido1), c12 = cos(keido1), c21 = cos(ido2), c22 = cos(keido2);
    double s11 = sin(ido1), s12 = sin(keido1), s21 = sin(ido2), s22 = sin(keido2);
    double dx = c11*c12 - c21*c22, dy = c11*s12 - c21*s22, dz = s11 - s21;
    return r * sqrt(dx*dx + dy*dy + dz*dz);
}

/*
  四面体の体積
  U : 辺AB の長さ
  V : 辺BC の長さ
  W : 辺CA の長さ
  u : 辺CD の長さ
  v : 辺AD の長さ
  w : 辺BD の長さ
  与えられた辺長から四面体が作れないときは, sqrt の引数が負になるかもしれない.
*/
double volume(double U, double V, double W, double u, double v, double w){
    double X = (w - U + v) * (U + v + w);
    double x = (U - v + w) * (v - w + U);
    double Y = (u - V + w) * (V + w + u);
    double y = (V - w + u) * (w - u + V);
    double Z = (v - W + u) * (W + u + v);
    double z = (W - u + v) * (u - v + W);
    double a = sqrt(x * Y * Z);
    double b = sqrt(y * Z * X);
    double c = sqrt(z * X * Y);
    double d = sqrt(x * y * z);
    return sqrt((-a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d))/(192 * u * v * w);
}

struct Sphere{
    Point3D p;
    double r;
    Sphere(){}
    Sphere(Point3D p,double r) : p(p), r(r) {}

    double surfaceArea(){
	return PI*r*r*4.0;
    }

    double volume(){
	return PI*r*r*r*4.0/3.0;
    }
};

bool cover(const Sphere &s,const Point3D &p){
    return (abs(s.p-p) < s.r + EPS);
}

#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
typedef Point3D Vector;
 
int ccw(Point3D p0,Point3D p1,Point3D p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(abs(cross(a,b)) > EPS) return COUNTER_CLOCKWISE;
    if(abs(cross(a,b)) < -EPS) return CLOCKWISE;
    if(dot(a,b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

/*
  vecが球と直線の交点
*/
bool isIntersectSL(const Sphere &c,const Segment &l){
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
