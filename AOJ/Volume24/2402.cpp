#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-8
#define equal(a,b) (fabs(a-b) < EPS)
#define PI M_PI
#define MAX_N 100
#define INF 1e9
 
class Point{
public:
    double x,y;
    Point(){}
    Point(double x,double y) : x(x),y(y) {}
 
    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k,y*k); }
};
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
 
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
 
class Segment{
public:
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};
 
class Star : public Point{
public:
    double a,r;
    vector<Segment> segs;
    Star(){}
    Star(Point p,double a,double r) : Point(p),a(a),r(r) {}
};
 
bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return (ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
	    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0);
}
 
Point projection(const Segment &s,const Point &p){
    Vector b = s.t-s.s;
    double t = dot(p-s.s,b)/norm(b);
    return s.s+b*t;
}
 
bool isIntersectSP(const Segment &s,const Point &p){
    return equal(ccw(s.s,s.t,p),0);
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
 
istream &operator >> (istream &is,Star &s){
    return is >> s.x >> s.y >> s.a >> s.r;
}
 
double toRad(double ang){ return ang*PI/180.0; }
 
Point rotate(const Point &bp,const Point &p,double th){
    double x = p.x, y = p.y;
    return Point(cos(th)*x-sin(th)*y+bp.x,sin(th)*x+cos(th)*y+bp.y);
}
 
void makeStar(vector<Star> &stars){
    int N = stars.size();
    for(int i = 0 ; i < N ; i++){
	double x = stars[i].x, y = stars[i].y;
	double r = stars[i].r, a = stars[i].a;
	Point bp(x,y), p(x,y+r);
	p = p - bp;
	p = rotate(bp,p,toRad(a));
	vector<Point> ps(5);
	for(int j = 0 ; j < 5 ; j++){
	    ps[j] = p;
	    p = p - bp;
	    p = rotate(bp,p,toRad(72));
	}
	stars[i].segs.resize(5);
	for(int j = 0 ; j < 5 ; j++){
	    stars[i].segs[j] = Segment(ps[j],ps[(j+2)%5]);
	}
    }
}
 
int main(){
    int N,M,L;
    while(cin >> N >> M >> L, N){
	vector<Star> stars(N);
	M--; L--;
	for(int i = 0 ; i < N ; i++){
	    cin >> stars[i];
	}
	makeStar(stars);
	double d[MAX_N][MAX_N];
	fill(d[0],d[0]+N*N,INF);
	for(int i = 0 ; i < N ; i++){
	    d[i][i] = 0;
	    for(int j = i+1 ; j < N ; j++){
		double dist = INF;
		for(int k = 0 ; k < 5 ; k++){
		    for(int l = 0 ; l < 5 ; l++){
			Segment s1 = stars[i].segs[k];
			Segment s2 = stars[j].segs[l];
			dist = min(dist,distanceSS(s1,s2));
		    }
		}
		d[i][j] = d[j][i] = dist;
	    }
	}
	for(int k = 0 ; k < N ; k++){
	    for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		}
	    }
	}
	printf("%.10f\n",d[M][L]);
    }
    return 0;
}
