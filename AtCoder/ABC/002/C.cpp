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
};
 
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
 
double getTriangleArea(const Point &a,const Point &b,const Point &c){
    double p = dist(a,b),q = dist(a,c),r = dist(b,c);
    double s = (p + q + r) / 2;
    return sqrt(s * (s-p) * (s-q) * (s-r));
}
 
int main(){
    Point a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    printf("%.5f\n",getTriangleArea(a,b,c));
    return 0;
}
