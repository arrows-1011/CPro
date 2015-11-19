#include <iostream>
#include <cmath>
 
using namespace std;
 
#define EPS 1e-7
 
class Point{
public:
    double x,y;
    Point(double x = 0.0,double y = 0.0) : x(x),y(y) {}
    Point operator + (Point p){ return Point(x+p.x, y+p.y); }
    Point operator - (Point p){ return Point(x-p.x, y-p.y); }
    Point operator * (double a){ return Point(x*a, y*a); }
    Point operator / (double a){ return Point(x/a, y/a); }
    double abs(){ return sqrt(norm()); }
    double norm(){ return x*x + y*y; }
};
 
typedef Point Vector;
double dot(Vector a,Vector b){
    return a.x*b.x + a.y*b.y;
}
double cross(Vector a,Vector b){
    return a.x*b.y - a.y*b.x;
}
 
class Segment{
public:
    Vector t,s;
    Segment(Vector t,Vector s) : t(t),s(s) {}
};
 
class Circle{
public:
    double x,y,r;
    Circle(double x = 0.0,double y = 0.0,double r = 0.0) : x(x),y(y),r(r) {}
};
 
Point point[3];
Circle ci;
 
int ccw(Point p0,Point p1,Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b) > EPS) return 1;
    if(cross(a,b) < -EPS) return -1;
    if(dot(a,b) < -EPS) return 2;
    if(a.norm() < b.norm()) return -2;
    return 0;
}
 
bool check(){
    Point cp = Point(ci.x,ci.y);
    int c1 = ccw(point[0],point[1],cp);
    int c2 = ccw(point[1],point[2],cp);
    int c3 = ccw(point[2],point[0],cp);
    return (c1 == c2 && c2 == c3);
}
 
typedef Segment Line;
double getDistanceLP(Line l,Point p){
    return abs(cross(l.s-l.t,p-l.t)/(l.s-l.t).abs());
}
 
double getDistanceSP(Segment seg,Point p){
    if(dot(seg.s-seg.t,p-seg.t) < 0.0) return (p-seg.t).abs();
    if(dot(seg.t-seg.s,p-seg.s) < 0.0) return (p-seg.s).abs(); 
    return getDistanceLP(seg,p);
}
 
int getStateCS(Circle c,Segment seg){
    Point cp = Point(c.x,c.y);
    if(getDistanceSP(seg,cp) >= c.r){
	return 1;
    }
    return 3;
}
 
bool isCross(){
    Point cp = Point(ci.x,ci.y);
 
    Segment seg[3] = {
	Segment(point[0],point[1]),
	Segment(point[1],point[2]),
	Segment(point[2],point[0])
    };
    int cnt = 0;
    for(int i = 0 ; i < 3 ; i++){
	if(getDistanceSP(seg[i],cp) > ci.r){
	    cnt++;
	}
    }
 
    if(cnt == 3 && !check()) return false;
    return true;
}
 
void judge(){
    Segment seg[3] = {
	Segment(point[0],point[1]),
	Segment(point[1],point[2]),
	Segment(point[2],point[0])
    };
    Point cp = Point(ci.x,ci.y);
    int TinC = 0;
    for(int i = 0 ; i < 3 ; i++,TinC++){
	if((point[i]-cp).abs() > ci.r){
	    break;
	}
    }
 
    if(TinC == 3){
	cout << 'b' << endl;
	return;
    }
 
    int CinT = 0;
    for(int i = 0 ; i < 3 ; i++){
	if(getStateCS(ci,seg[i]) == 1){
	    CinT++;
	}
    }
 
    if(CinT == 3 && check()){
	cout << 'a' << endl;
    }else{
	if(isCross()){
	    cout << 'c' << endl;
	}else{
	    cout << 'd' << endl;
	}
    }
}
 
int main(){
    while(true){
	cin >> point[0].x >> point[0].y;
	if(!point[0].x && !point[0].y) break;
	for(int i = 0 ; i < 2 ; i++){
	    cin >> point[i+1].x >> point[i+1].y;
	}
	cin >> ci.x >> ci.y >> ci.r;
	judge();
    }
    return 0;
}
