#include<bits/stdc++.h>
  
using namespace std;
  
#define MAX_N 20
#define MAX_C 10001
#define INF 1e9
#define EPS 1e-9
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (equal(a,b) || lt(a,b))
#define PI acos(-1)
  
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y) : x(x),y(y) {}
    
    Point operator + (const Point &p)const{
	return Point(x+p.x,y+p.y);
    }
    Point operator - (const Point &p)const{
	return Point(x-p.x,y-p.y);
    }
    Point operator * (double k)const{
	return Point(x*k,y*k);
    }
};
  
istream &operator >> (istream &is,Point &p){
    return is >> p.x >> p.y;
}
  
struct State{
    double d;
    int v,p,c;
    
    State(double d,int v,int p,int c) : 
	d(d),v(v),p(p),c(c) {}
    
    bool operator < (const State &s)const{
	return d > s.d;
    }
};
  
double dot(const Point &a,const Point &b){
    return a.x*b.x+a.y*b.y;
}
  
double norm(const Point &p){
    return dot(p,p);
}
  
double abs(const Point &p){
    return sqrt(norm(p));
}
  
typedef Point Vector;
  
inline double getAngle(const Vector &a,const Vector &b){
    return acos(dot(a,b)/abs(a)/abs(b))*180/PI;
}
  
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
  
int N;
double r,th,d2[MAX_N][MAX_N];
bool can[MAX_N][MAX_N][MAX_N];
double d[MAX_N][MAX_N][MAX_C];
  
int solve(const vector<Point> &vec){
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    for(int k = 0 ; k < MAX_C ; k++){
		d[i][j][k] = INF;
	    }
	}
    }
    priority_queue<State> Q;
    for(int i = 1 ; i < N ; i++){
	Q.push(State(dist(vec[0],vec[i]),i,0,1));
	d[i][0][1] = dist(vec[0],vec[i]);
    }
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.v,p = s.p,c = s.c;
	if(lt(d[v][p][c],s.d)) continue;
	if(lt(r,s.d)) continue;
	for(int i = 0 ; i < N ; i++){
	    if(i == v || i == p) continue;
	    if(!can[p][v][i]) continue;
	    if(c+1 < MAX_C && lt(d[v][p][c]+d2[v][i],d[i][v][c+1])){
		d[i][v][c+1] = d[v][p][c]+d2[v][i];
		Q.push(State(d[i][v][c+1],i,v,c+1));
	    }
	}
    }
    int ans = 0;
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    if(i == j) continue; 
	    for(int k = MAX_C-1 ; k > 0 ; k--){
		if(le(d[i][j][k],r)){
		    ans = max(ans,k);
		    break;
		}
	    }
	}
    }
    return ans;
}
  
int main(){
    cin >> N >> r >> th;
    vector<Point> v(N);
    for(int i = 0 ; i < N ; i++){
	cin >> v[i];
    }
    memset(can,false,sizeof(can));
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    if(i == j) continue; 
	    for(int k = 0 ; k < N ; k++){
		if(i == k || j == k) continue;
		Vector a = v[j]-v[i];
		Vector b = v[k]-v[j];
		double angle = getAngle(a,b);
		if(le(angle,th)){
		    can[i][j][k] = true;
		}
	    }
	}
    }
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    d2[i][j] = dist(v[i],v[j]);
	}
    }
    cout << solve(v) << endl;
    return 0;
}
