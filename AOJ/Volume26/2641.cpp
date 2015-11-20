#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (lt(a,b) || equal(a,b))
typedef long long ll;
 
class Point{
public:
    Point(){}
    Point(double x,double y,double z) : x(x), y(y), z(z) {}
   
    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y,z+p.z); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y,z-p.z); }
    Point operator * (double k)const{ return Point(x*k,y*k,z*k); }
    Point operator / (double k)const{ return Point(x/k,y/k,z/k); }
    double x,y,z;
};
 
double dot(const Point &a,const Point &b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}
 
Point cross(const Point &a,const Point &b){
    return Point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
 
double norm(const Point &p){
    return dot(p,p);
}
 
double abs(const Point &p){
    return sqrt(norm(p));
}
 
istream &operator >> (istream &is,Point &p){
    return is >> p.x >> p.y >> p.z;
}
 
class Line{
public:
    Line(){}
    Line(Point s,Point t) : s(s), t(t) {}
    Point s,t;
};
 
Point projection(const Line &l,const Point &p){
    Point b = l.t - l.s;
    double t = dot(p-l.s,b)/norm(b);
    return l.s + b*t;
}
 
double distanceLP(const Line &l,const Point &p){
    return abs(p-projection(l,p));
}
 
class Cube{
public:
    Cube(){}
    Cube(Point p,double r) : p(p), r(r) {}
    Point p;
    double r;
};
 
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
typedef Point Vector;
  
int ccw(Point p0,Point p1,Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(abs(cross(a,b)) > EPS) return COUNTER_CLOCKWISE; 
    if(abs(cross(a,b)) < -EPS) return CLOCKWISE; 
    if(dot(a,b) < -EPS) return ONLINE_BACK; 
    if(norm(a) < norm(b)) return ONLINE_FRONT; 
    return ON_SEGMENT;
}
 
bool isIntersectCL(const Cube &c,const Line &l){
    vector<Point> vec;
    double d = distanceLP(l,c.p);
    if(le(d,c.r)){
	Point p = projection(l,c.p);
	Point v = (l.t - l.s) / abs(l.t - l.s);
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
 
class Obj{
public:
    Obj(){}
    Obj(Cube c,ll l) : c(c), l(l) {}
    Cube c;
    ll l;
};
 
int main(){
    int N,Q;
    cin >> N >> Q;
    vector<Obj> obj(N);
    for(int i = 0 ; i < N ; i++){
	cin >> obj[i].c.p >> obj[i].c.r >> obj[i].l;
    }
    for(int i = 0 ; i < Q ; i++){
	Line l;
	cin >> l.s >> l.t;
	ll res = 0LL;
	for(int j = 0 ; j < N ; j++){
	    if(isIntersectCL(obj[j].c,l)){
		res += obj[j].l;
	    }
	}
	cout << res << endl;
    }
    return 0;
}
