#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-9
 
struct Point{
    double x,y;
   
    Point(){}
    Point(double x,double y) : x(x),y(y) {}
   
    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k,y*k); }
    Point operator / (const double &k)const{ return Point(x/k,y/k); }
};
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
 
istream &operator >> (istream &is,Point &p){
    return is >> p.x >> p.y;
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
 
bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return (ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
	    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0);
}
 
Point crosspointSS(const Segment &a,const Segment &b){
    Vector va = a.t-a.s, vb = b.t-b.s;
    double d = cross(vb,va);
    return a.s+va*cross(vb,b.t-a.s)*(1.0/d);
}
 
struct P{
    int comp;
    int pos;
    double dist;
 
    bool operator < (const P &p)const{
	if(dist != p.dist){
	    return dist < p.dist;
	}
    }
};
 
int solve(int idx,int p,vector<P> &v){
    if(idx == (int)v.size()) return 0;
    int res;
    if(v[idx].comp == 0){
	if(p == v[idx].pos){
	    res = solve(idx+1,!p,v)+1;
	}else{
	    res = solve(idx+1,p,v);
	}
    }else{
	if(p == v[idx].pos){
	    res = solve(idx+1,p,v);
	}else{
	    res = solve(idx+1,!p,v)+1;
	}
    }
    return res;
}
 
int main(){
    int Tc,N,comp,pos;
    cin >> Tc;
    while(Tc--){
	Segment s,line;
	cin >> s.s >> s.t >> N;
	vector<P> vec;
	for(int i = 0 ; i < N ; i++){
	    cin >> line.s >> line.t >> comp >> pos;
	    if(isIntersectSS(line,s)){
		Point p = crosspointSS(line,s);
		double d = dist(p,s.s);
		vec.push_back((P){comp,pos,d});
	    }
	}
	sort(vec.begin(),vec.end());
	cout << min(solve(0,0,vec),solve(0,1,vec)) << endl;
    }
    return 0;
}
