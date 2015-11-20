#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define INF 1e8
#define equal(a,b) (fabs(a-b) < EPS)
#define not_equal(a,b) (!equal(a,b))
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
 
istream &operator >> (istream &is,Point &p){ 
    return is >> p.x >> p.y;
}
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
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
    return (ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
	    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0);
}
 
struct State{
    double d;
    int v;
    State(double d,int v) : d(d),v(v) {}
   
    bool operator < (const State &s)const{
	if(not_equal(d,s.d)){
	    return lt(s.d,d);
	}
    }
};
 
double solve(int x,vector<Point> A[2]){
    priority_queue<State> Q;
    Q.push(State(0,0));
    double d[1010];
    fill(d,d+1010,INF);
    d[0] = 0;
   
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.v;
	if(lt(d[v],s.d)) continue; 
	if(v == 1) return d[v];
	for(int i = 1 ; i < (int)A[x].size() ; i++){
	    if(v == i) continue;
	    Segment s1(A[x][v],A[x][i]),s2(A[1-x][0],A[1-x][1]);
	    if(isIntersectSS(s1,s2)) continue;
	    double nd = d[v]+dist(A[x][v],A[x][i]);
	    if(lt(nd,d[i])){
		d[i] = nd;
		Q.push(State(d[i],i));
	    }
	}
    }
    return INF;
}
 
int main(){
    int N,M;
    vector<Point> A[2];
    cin >> N >> M;
    A[0].resize(N); A[1].resize(M);
    for(int i = 0 ; i < N ; i++){
	cin >> A[0][i];
    }
    for(int i = 0 ; i < M ; i++){
	cin >> A[1][i];
    }
    double res = INF;
    Segment s[2] = {Segment(A[0][0],A[0][1]),
		    Segment(A[1][0],A[1][1])};
    for(int i = 0 ; i < 2 ; i++){
	res = min(res,solve(1-i,A)+dist(s[i].s,s[i].t));
    }
    if(res == INF){
	cout << -1 << endl;
    }else{
	printf("%.10f\n",res);
    }
    return 0;
}
