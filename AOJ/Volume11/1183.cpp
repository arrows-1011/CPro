#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 110
#define INF 1e9
#define EPS 1e-10
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
 
Point operator * (const Point &a,const Point &b){ return Point(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
double getDistance(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
 
istream &operator >> (istream &is,Point &p){ 
    return is >> p.x >> p.y;
}
 
typedef Point Vector;
 
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
typedef Point Vector;
 
int ccw(Point p0,Point p1,Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b) > EPS){ return COUNTER_CLOCKWISE; }
    if(cross(a,b) < -EPS){ return CLOCKWISE; }
    if(dot(a,b) < -EPS){ return ONLINE_BACK; }
    if(norm(a) < norm(b)){ return ONLINE_FRONT; }
    return ON_SEGMENT;
}
 
struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};
 
struct Circle{
    Point p;
    double r;
    Circle(){}
    Circle(Point p,double r) : p(p),r(r) {}
};
 
bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0
	&& ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
 
vector<Point> crosspointCC(const Circle &a,const Circle &b){
    vector<Point> res;
    double d = abs(a.p-b.p);
    double rc = (a.r*a.r-b.r*b.r+d*d)/(2.0*d);
    double rs = sqrt(a.r*a.r-rc*rc);
    Point p = (b.p-a.p)/d;
    res.push_back(Point(a.p+p*Point(rc,-rs)));
    res.push_back(Point(a.p+p*Point(rc,rs)));
    return res;
}
 
struct P{
    double d;
    int n,p;
    P(double d,int n,int p) : d(d),n(n),p(p) {}
    bool operator < (const P &p)const{
	if(d != p.d){
	    return d > p.d;
	}
    }
};
 
double dist[MAX_N][2][MAX_N][2];
 
double solve(int N){
    double d[MAX_N][2];
    fill(d[0],d[0]+MAX_N*2,INF);
    d[0][0] = 0.0;
 
    priority_queue<P> Q;
    Q.push(P(0,0,0));
 
    while(!Q.empty()){
	P p = Q.top(); Q.pop();
	int idx = p.n,pos = p.p;
	if(lt(d[idx][pos],p.d)){ continue; }
	if(idx == N){ return p.d; }
	for(int i = idx+1 ; i <= N ; i++){
	    for(int j = 0 ; j < 2 ; j++){
		if(dist[idx][pos][i][j] == INF){ continue; }
		if(p.d+dist[idx][pos][i][j] < d[i][j]){
		    d[i][j] = p.d+dist[idx][pos][i][j];
		    Q.push(P(d[i][j],i,j));
		}
	    }
	}
    }
    return -1;
}
 
void init(int N){
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < 2 ; j++){
	    for(int k = 0 ; k <= N ; k++){
		for(int l = 0 ; l < 2 ; l++){
		    dist[i][j][k][l] = INF;
		}
	    }
	}
    }
}
 
int main(){
    int N;
    while(cin >> N,N){
	vector<Point> G[MAX_N];
	vector<Circle> cirs(N);
	init(N);
	for(int i = 0 ; i < N ; i++){
	    cin >> cirs[i].p >> cirs[i].r;
	    if(i == 0){
		G[i].push_back(cirs[0].p);
		G[i].push_back(cirs[0].p);
	    }else{
		vector<Point> cp = crosspointCC(cirs[i-1],cirs[i]);
		G[i].push_back(cp[0]); G[i].push_back(cp[1]);
	    }
	}
	G[N].push_back(cirs[N-1].p);
	G[N].push_back(cirs[N-1].p);
 
	for(int i = 0 ; i < N ; i++){
	    for(int j = i+1 ; j <= N ; j++){
		Point p1[2] = {G[i][0],G[i][1]};
		Point p2[2] = {G[j][0],G[j][1]};
		for(int k = 0 ; k < 2 ; k++){
		    for(int l = 0 ; l < 2 ; l++){
			Segment a = Segment(p1[k],p2[l]);
			bool ok = true;
			for(int m = i ; m < j ; m++){
			    Segment b = Segment(G[m][0],G[m][1]);
			    if(!isIntersectSS(a,b)){
				ok = false;
				break;
			    }
			}
			if(ok){
			    dist[i][k][j][l] = getDistance(p1[k],p2[l]);
			}
		    }
		}
	    }
	}
	printf("%.8f\n",solve(N));
    }
    return 0;
}
