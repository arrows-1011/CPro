#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define INF 1e9
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
 
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
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
 
bool isParallelSS(const Segment &s1,const Segment &s2){
    Vector a = s1.t-s1.s;
    Vector b = s2.t-s2.s;
    return equal(cross(a,b),0);
}
 
Point getPoint(vector<Point> &p,int N){
    for(int i = 0 ; i < N/2 ; i++){
	Segment a = Segment(p[i],p[i+1]);
	Segment b = Segment(p[N/2+i],p[(N/2+i+1)%N]);
	if(!isParallelSS(a,b)) return Point(INF,INF);
	if(!equal(dist(a.s,a.t),dist(b.s,b.t))){
	    return Point(INF,INF);
	}
    }
    return (p[0]+p[N/2])/2;
}
 
int main(){
    int N;
    cin >> N;
    vector<Point> p(N);
    for(int i = 0 ; i < N ; i++){
	cin >> p[i];
    }
    if(N&1){
	cout << "NA" << endl;
    }else{
	Point res = getPoint(p,N);
	if(res.x == INF && res.y == INF){
	    cout << "NA" << endl;
	}else{
	    printf("%.8f %.8f\n",res.x,res.y);
	}
    }
    return 0;
}
