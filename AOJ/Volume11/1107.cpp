#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define MAX_N 400
#define INF 1e9
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
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
 
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
 
istream &operator >> (istream &is,Point &p){
    return is >> p.x >> p.y;
}
 
typedef Point Vector;
 
struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};
 
int main(){
    int N;
    while(cin >> N, N){
	Point np(0,0);
	Vector v(0,1);
	vector<Point> p(N);
	for(int i = 0 ; i < N ; i++){
	    cin >> p[i];
	}
	double res = 0;
	bool visited[MAX_N] = {false};
	for(int i = 0 ; i < N ; i++){
	    int idx = -1;
	    double min = INF,d = INF;
	    for(int j = 0 ; j < N ; j++){
		if(visited[j]){ continue; }
		Vector v2 = p[j]-np;
		double angle = acos(dot(v,v2)/abs(v)/abs(v2));
		if(lt(angle,min)){
		    d = dist(np,p[j]);
		    min = angle;
		    idx = j;
		}else if(equal(angle,min)){
		    if(lt(dist(np,p[j]),d)){
			d = dist(np,p[j]);
			min = angle;
			idx = j;
		    }
		}
	    }
	    visited[idx] = true;
	    res += dist(np,p[idx]);
	    v = p[idx]-np;
	    np = p[idx];
	}
	printf("%.1f\n",res);
    }
    return 0;
}
