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
    Point projection(Point &p){
	Vector b = s - t;
	double d = dot(p-t,b) / b.norm();
	return t + b*d;
    }
};
 
class Circle{
public:
    double x,y,r;
    Circle(double x = 0.0,double y = 0.0,double r = 0.0) : x(x),y(y),r(r) {}
};
 
int N;
Point t,s;
Circle ci[300];
 
bool check(Point p0,Point p1,Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b) > EPS) return false;
    if(cross(a,b) < -EPS) return false;
    if(dot(a,b) < -EPS) return false;
    if(a.norm() < b.norm()) return false;
    return true;
}
 
bool getStateCS(Circle c,Segment seg){
    Point cp = Point(c.x,c.y);
    Point p = seg.projection(cp);
    Point pp = p - cp;
 
 
    Vector a = seg.t - cp;
    Vector b = seg.s - cp;
     
    if((a.abs() > c.r && b.abs() < c.r) ||
       (a.abs() < c.r && b.abs() > c.r) ) return true;
    if(a.abs() > c.r && b.abs() > c.r){
	if(pp.abs()-EPS < c.r && check(seg.t,seg.s,p)){
	    return true;
	}
    }
    return false;
}
 
bool judge(){
    Segment seg = Segment(t,s);
 
    for(int i = 0 ; i < N ; i++){
	if(getStateCS(ci[i],seg)) return true;
    }
    return false;
}
 
int main(){
    int M;
  
    while(cin >> N,N){
	for(int i = 0 ; i < N ; i++){
	    cin >> ci[i].x >> ci[i].y >> ci[i].r;
	}
	cin >> M;
	for(int i = 0 ; i < M ; i++){
	    cin >> t.x >> t.y >> s.x >> s.y; 
	    if(judge()){
		cout << "Safe" << endl;
	    }else{
		cout << "Danger" << endl;
	    }
	}
    }
    return 0;
}
