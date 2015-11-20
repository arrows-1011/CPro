#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 35
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
 
typedef Point Vector;
typedef vector<Point> Polygon;
 
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
 
ostream &operator << (ostream &os,Point &p){ 
    return os << "(" << p.x << "," << p.y << ")";
}
 
struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};
 
Point crosspointSS(const Segment &a,const Segment &b){
    Vector va = a.t-a.s, vb = b.t-b.s;
    double d = cross(vb,va);
    return a.s+va*cross(vb,b.t-a.s)*(1.0/d);
}
 
double getArea(const Polygon &p){
    int N = p.size();
    double res = 0;
    for(int i = 1 ; i < N+1 ; i++){
	res += (p[i%N].x-p[i-1].x)*(p[i%N].y+p[i-1].y);
    }
    res /= 2.0;
    return abs(res);
}
 
int main(){
    int N;
    while(cin >> N,N){
	double in;
	vector<Point> p[4];
	Point q[MAX][MAX];
	q[0][0] = Point(0,0);
	q[0][N+1] = Point(0,1);
	q[N+1][0] = Point(1,0);
	q[N+1][N+1] = Point(1,1);
	for(int i = 0 ; i < 2 ; i++){
	    p[i].resize(N);
	    for(int j = 0 ; j < N ; j++){
		cin >> in;
		p[i][j] = Point(in,i);
		if(i == 0){
		    q[j+1][0] = p[i][j];
		}else{
		    q[j+1][N+1] = p[i][j];
		}
	    }
	}
	for(int i = 2 ; i < 4 ; i++){
	    p[i].resize(N);
	    for(int j = 0 ; j < N ; j++){
		cin >> in;
		p[i][j] = Point(i-2,in);
		if(i == 2){
		    q[0][j+1] = p[i][j];
		}else{
		    q[N+1][j+1] = p[i][j];
		}
	    }
	}
	vector<Segment> s[2];
	for(int i = 0 ; i < N ; i++){
	    s[0].push_back(Segment(p[0][i],p[1][i]));
	}
	for(int i = 0 ; i < N ; i++){
	    s[1].push_back(Segment(p[2][i],p[3][i]));
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		Point cp = crosspointSS(s[0][i],s[1][j]);
		q[i+1][j+1] = cp;
	    }
	}
	double res = 0;
	for(int i = 0 ; i <= N ; i++){
	    for(int j = 0 ; j <= N ; j++){
		Polygon pg(4);
		pg[0] = q[i][j];
		pg[1] = q[i][j+1];
		pg[2] = q[i+1][j+1];
		pg[3] = q[i+1][j];
		res = max(res,getArea(pg));
	    }
	}
	printf("%.10f\n",res);
    }
    return 0;
}
