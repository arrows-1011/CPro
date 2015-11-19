#include <iostream>
#include <cmath>
 
using namespace std;
 
#define EPS 1e-8
 
struct Point{
    double x,y;
    Point(double x = 0.0, double y = 0.0) : x(x),y(y) {}
    Point operator + (Point p){ return Point(x+p.x,y+p.y); }
    Point operator - (Point p){ return Point(x-p.x,y-p.y); }
    Point operator * (double a){ return Point(x*a,y*a); }
    Point operator / (double a){ return Point(x/a,y/a); }
    double abs(){ return sqrt(norm()); }
    double norm(){ return x*x + y*y; }
};
 
typedef Point Vector;
double dot(Vector a,Vector b){ return a.x*b.x+a.y*b.y; }
double cross(Vector a,Vector b){ return a.x*b.y-a.y*b.x; }
 
int ccw(Point p0,Point p1,Point p2){
    Vector a = p1-p0;
    Vector b = p2-p0;
    if(cross(a,b) > EPS) return 1;
    if(cross(a,b) < -EPS) return -1;
    if(dot(a,b) < -EPS) return 2;
    if(a.norm() < b.norm()) return -2;
    return 0;
}
 
struct Segment{
    Vector p1,p2;
    Segment(){}
    Segment(Vector p1,Vector p2) : p1(p1),p2(p2) {}
};
 
bool intersectSS(const Segment &s,const Segment &t){
    return (ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0) && 
	(ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0);
}
 
Point getCrossPoint(Segment s,Segment t){
    Vector b = t.p2 - t.p1;
    double d1 = abs(cross(b,s.p1-t.p1));
    double d2 = abs(cross(b,s.p2-t.p1));
    double d = d1 / (d1 + d2);
    return s.p1+(s.p2-s.p1)*d;
}
 
double getArea(Point a,Point b,Point c){
    return fabs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2;
}
 
Segment s[3];
void solve(){
    Point p1 = getCrossPoint(s[0],s[1]);
    Point p2 = getCrossPoint(s[1],s[2]);
    Point p3 = getCrossPoint(s[2],s[0]);
    double S = getArea(p1,p2,p3);
    if(S >= 1900000){
	cout << "dai-kichi" << endl;
    }else if(S >= 1000000){
	cout << "chu-kichi" << endl;
    }else if(S >= 100000){
	cout << "kichi" << endl;
    }else if(S > 0){
	cout << "syo-kichi" << endl;
    }else{
	cout << "kyo" << endl;
    }
}
 
int main(){
    while(true){
	cin >> s[0].p1.x >> s[0].p1.y >> s[0].p2.x >> s[0].p2.y;
	if(!s[0].p1.x && !s[0].p1.y && !s[0].p2.x && !s[0].p2.y) break;
 
	for(int i = 0 ; i < 2 ; i++){
	    cin >> s[i+1].p1.x >> s[i+1].p1.y >> s[i+1].p2.x >> s[i+1].p2.y;
	}
	if(intersectSS(s[0],s[1]) && intersectSS(s[1],s[2]) && intersectSS(s[2],s[0])){
	    solve();
	}else{
	    cout << "kyo" << endl;
	}
    }
    return 0;
}
