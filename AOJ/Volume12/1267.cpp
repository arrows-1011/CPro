#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
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
 
typedef Segment Line;
 
Point crosspointLL(const Line &a,const Line &b){
    Vector va = a.t-a.s, vb = b.t-b.s;
    double d = cross(vb,va);
    if(abs(d) < EPS) return b.s;
    return a.s+va*cross(vb,b.t-a.s)*(1.0/d);
}
 
#define curr(G,i) (G[i%G.size()])
#define next(G,i) (G[(i+1)%G.size()])
typedef vector<Point> Polygon;
 
Polygon convex_cut(const Polygon &pg,const Line &l){
    Polygon res;
    for(int i = 0 ; i < (int)pg.size() ; i++){
	Point cp = curr(pg,i), np = next(pg,i);
	if(ccw(l.s,l.t,cp) != -1){ res.push_back(cp); }
	if(ccw(l.s,l.t,cp)*ccw(l.s,l.t,np) < 0){
	    res.push_back(crosspointLL(Line(cp,np),l));
	}
    }
    return res;
}
 
int main(){
    int N;
    while(cin >> N, N){
	Polygon pg(N);
	for(int i = 0 ; i < N ; i++){
	    cin >> pg[i].x >> pg[i].y;
	}
	Polygon pg2;
	pg2.push_back(Point(0,0));
	pg2.push_back(Point(10000,0));
	pg2.push_back(Point(10000,10000));
	pg2.push_back(Point(0,10000));
	for(int i = 0 ; i < N ; i++){
	    Line l = Line(curr(pg,i),next(pg,i));
	    pg2 = convex_cut(pg2,l);
	}
	cout << (pg2.size() > 0 ? 1 : 0) << endl;
    }
    return 0;
}
