#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define not_equal(a,b) (!equal(a,b))
#define lt(a,b) (a-b < -EPS)
 
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
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
 
istream &operator >> (istream &is,Point &p){ 
    return is >> p.x >> p.y;
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
    if(cross(a,b) > EPS) return COUNTER_CLOCKWISE; 
    if(cross(a,b) < -EPS) return CLOCKWISE; 
    if(dot(a,b) < -EPS) return ONLINE_BACK; 
    if(norm(a) < norm(b)) return ONLINE_FRONT; 
    return ON_SEGMENT;
}
 
struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};
 
Point projection(const Segment &s,const Point &p){
    Vector b = s.t-s.s;
    double t = dot(p-s.s,b)/norm(b);
    return s.s+b*t;
}
 
bool isIntersectSP(const Segment &s,const Point &p){
    return equal(ccw(s.s,s.t,p),0);
}
 
bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return (ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0
	    && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0);
}
 
double distanceSP(const Segment &s,const Point &p){
    Point r = projection(s,p);
    if(isIntersectSP(s,r)){ return abs(r-p); }
    return min(abs(s.s-p),abs(s.t-p));
}
 
double distanceSS(const Segment a,const Segment b){
    if(isIntersectSS(a,b)) return 0; 
    return min(min(distanceSP(a,b.s),distanceSP(a,b.t)),
	       min(distanceSP(b,a.s),distanceSP(b,a.t)));
}
 
int main(){
    int N1,N2;
    vector<Point> p[2];
    cin >> N1;
    p[0].resize(N1+2);
    p[0][0] = Point(0,0);
    p[0][N1+1] = Point(1000,0);
    for(int i = 1 ; i <= N1 ; i++){
	cin >> p[0][i];
    }
    cin >> N2;
    p[1].resize(N2+2);
    p[1][0] = Point(0,1000);
    p[1][N2+1] = Point(1000,1000);
    for(int i = 1 ; i <= N2 ; i++){
	cin >> p[1][i];
    }
    vector<Segment> s[2];
    for(int i = 1 ; i <= N1+1 ; i++){
	s[0].push_back(Segment(p[0][i-1],p[0][i]));
    }
    for(int i = 1 ; i <= N2+1 ; i++){
	s[1].push_back(Segment(p[1][i-1],p[1][i]));
    }
    double res = (1<<29);
    int l1 = s[0].size(), l2 = s[1].size();
    for(int i = 0 ; i < l1 ; i++){
	for(int j = 0 ; j < l2 ; j++){
	    res = min(res,distanceSS(s[0][i],s[1][j]));
	}
    }
    printf("%.10f\n",res);
    return 0;
}
