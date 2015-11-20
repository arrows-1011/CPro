#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
  
using namespace std;
  
#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
  
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
  
bool isIntersectSP(const Segment &s,const Point &p){
    return equal(ccw(s.s,s.t,p),0);
}
  
bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0
	&& ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
  
#define prev(G,i) (G[(i-1+G.size())%G.size()])
#define curr(G,i) (G[i%G.size()])
#define next(G,i) (G[(i+1)%G.size()])
typedef vector<Point> Polygon;
  
bool check(const Polygon &pg,const Point &p){
    int N = pg.size();
    bool in = false;
    for(int i = 0 ; i < N ; i++){
	Point a = curr(pg,i)-p, b = next(pg,i)-p;
	if(a.y > b.y) swap(a,b);
	if(a.y <= 0 && 0 < b.y && cross(a,b) > 0) in = !in;
	if(cross(a,b) == 0 && dot(a,b) <= 0) return true;
    }
    return in;
}
 
bool sortY(Point p1,Point p2){
    if(p1.y != p2.y){
	return (p1.y - p2.y < -EPS);
    }else{ 
	return (p1.x - p2.x < -EPS);
    }
}
 
Polygon convex_hull(Polygon &ps){
    int N = ps.size(),j = 0;
    Polygon pg(N*2);
    sort(ps.begin(),ps.end(),sortY);
    for(int i = 0 ; i < N ; i++,j++){
	while(j >= 2 && ccw(pg[j-2],pg[j-1],ps[i]) == -1){
	    j--;
	}
	pg[j] = ps[i];
    }
    int k = j+1;
    for(int i = N-2 ; i >= 0 ; i--,j++){
	while(j >= k && ccw(pg[j-2],pg[j-1],ps[i]) == -1){
	    j--;
	}
	pg[j] = ps[i];
    }
    pg.resize(j-1);
    return pg;
}
  
bool solve(Polygon &bp,Polygon &wp){
    int N = bp.size(), M = wp.size();
    if(N == 1 && M == 1){
	return !(equal(bp[0].x,wp[0].x) && equal(bp[0].y,wp[0].y));
    }
    if(N == 2 && M == 1){
	Segment s(bp[0],bp[1]);
	return !isIntersectSP(s,wp[0]);
    }
    if(N == 1 && M == 2){
	Segment s(wp[0],wp[1]);
	return !isIntersectSP(s,bp[0]);
    }
    if(N == 2 && M == 2){
	Segment s1(bp[0],bp[1]),s2(wp[0],wp[1]);
	return !isIntersectSS(s1,s2);
    }
    bp = convex_hull(bp);
    wp = convex_hull(wp);
    if(N == 1 && M >= 3){
	return !check(wp,bp[0]);
    }
    if(N >= 3 && M == 1){
	return !check(bp,wp[0]);
    }
    if(N == 2 && M >= 3){
	Segment s1(bp[0],bp[1]);
	if(check(wp,bp[0]) || check(wp,bp[1])){
	    return false;
	}
	for(int i = 0 ; i < M ; i++){
	    for(int j = i+1 ; j < M ; j++){
		Segment s2(wp[i],wp[j]);
		if(isIntersectSS(s1,s2)){
		    return false;
		}
	    }
	}
	return true;
    }
    if(N >= 3 && M == 2){
	Segment s1(wp[0],wp[1]);
	if(check(bp,wp[0]) || check(bp,wp[1])){
	    return false;
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = i+1 ; j < N ; j++){
		Segment s2(bp[i],bp[j]);
		if(isIntersectSS(s1,s2)){
		    return false;
		}
	    }
	}
	return true;
    }
    for(int i = 0 ; i < N ; i++){
	if(check(wp,bp[i])){
	    return false;
	}
    }
    for(int i = 0 ; i < M ; i++){
	if(check(bp,wp[i])){
	    return false;
	}
    }
    return true;
}
  
int main(){
    int N,M;
    while(cin >> N >> M,N){
	Polygon bp(N),wp(M);
	for(int i = 0 ; i < N ; i++){
	    cin >> bp[i];
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> wp[i];
	}
	cout << (solve(bp,wp) ? "YES" : "NO") << endl;
    }
    return 0;
}
