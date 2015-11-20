#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-8
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define MAX_N 100
#define MAX_P 500
#define INF 1e9
 
struct Point{
    double x,y;
 
    Point(){}
    Point(double x,double y) : x(x),y(y) {}
 
    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k,y*k); }
    Point operator / (const double &k)const{ return Point(x/k,y/k); }
    bool operator < (const Point &p)const{
	if(!equal(x,p.x)){
	    return lt(x,p.x);
	}else{
	    return lt(y,p.y);
	}
    }
    bool operator == (Point &p)const{
	if(equal(x,p.x) && equal(y,p.y)){
	    return true;
	}
	return false;
    }
};
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
 
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
typedef Point Vector;
 
int ccw(const Point &p0,const Point &p1,const Point &p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b) < -EPS) return CLOCKWISE;
    if(dot(a,b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;
    return ON_SEGMENT;
}
 
typedef Point Vector;
 
struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
    bool operator == (Segment &seg)const{
	if(s == seg.s && t == seg.t){
	    return true;
	}
	if(t == seg.s && s == seg.t){
	    return true;
	}
	return false;
    }
};
 
bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return (ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0
	    && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0);
}
 
Point crosspointSS(const Segment &a,const Segment &b){
    Vector va = a.t-a.s, vb = b.t-b.s;
    double d = cross(vb,va);
    return a.s+va*cross(vb,b.t-a.s)*(1.0/d);
}
 
struct Line{
    Point s,t;
    Line(){}
    Line(Point s,Point t) : s(s),t(t) {}
};
 
Point projection(const Line &l,const Point &p){
    Vector b = l.t-l.s;
    double t = dot(p-l.s,b)/norm(b);
    return l.s+b*t;
}
 
Point reflection(const Line &l,const Point &p){
    return p+(projection(l,p)-p)*2.0;
}
 
#define curr(G,i) (G[i%G.size()])
#define next(G,i) (G[(i+1)%G.size()])
typedef vector<Point> Polygon;
 
int containPP(const Polygon &pg,const Point &p){
    int N = pg.size();
    bool in = false;
    for(int i = 0 ; i < N ; i++){
	Point a = curr(pg,i)-p, b = next(pg,i)-p;
	if(a.y > b.y){ swap(a,b); }
	if(a.y <= 0 && 0 < b.y && cross(a,b) < 0){ in = !in; }
	if(cross(a,b) == 0 && dot(a,b) <= 0){ return 1; }
    }
    return (in ? 2 : 0);
}
 
struct Data{
    Point p;
    double d;
    Data(Point p,double d) : p(p),d(d) {}
    bool operator < (const Data &data)const{
	if(!equal(d,data.d)){
	    return lt(d,data.d);
	}else{
	    return p < data.p;
	}
    }
};
 
bool containPS(const Polygon &pg,Segment &s){
    vector<Data> v;
    v.push_back(Data(s.s,0));
    v.push_back(Data(s.t,dist(s.s,s.t)));
    set<Point> st;
    for(int i = 0 ; i < (int)pg.size() ; i++){
	Segment seg(curr(pg,i),next(pg,i));
	if(seg == s) return true;
	if(ccw(seg.s,seg.t,s.s) == 0 && ccw(seg.s,seg.t,s.t) == 0){
	    return true;
	}
 
	if(isIntersectSS(s,seg)){
	    Point cp = crosspointSS(s,seg);
	    double d = dist(cp,s.s);
	    if(st.find(cp) != st.end()){
		continue;
	    }
	    st.insert(cp);
	    v.push_back(Data(cp,d));
	}
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i < (int)v.size()-1 ; i++){
	Point cp = (v[i].p + v[i+1].p) / 2.0;
	if(containPP(pg,cp) == 0){
	    return false;
	}
    }
    return true;
}
 
struct Edge{
    int to;
    double cost;
    Edge(int to,double cost) : to(to),cost(cost) {}
};
 
struct State{
    int v;
    double d;
    State(int v,double d) : v(v),d(d) {}
    bool operator < (const State &s)const{
	return d > s.d;
    }
};
 
Polygon L,R;
vector<Edge> G[MAX_P];
 
double dijkstra(int s,int t){
    double dist[MAX_P];
    fill(dist,dist+MAX_P,INF);
    dist[s] = 0;
    priority_queue<State> Q;
    Q.push(State(s,0));
    while(!Q.empty()){
	State st = Q.top(); Q.pop();
	int v = st.v;
	if(lt(dist[v],st.d)){
	    continue;
	}
	if(v == t) return dist[t];
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge e = G[v][i];
	    if(lt(dist[v]+e.cost,dist[e.to])){
		dist[e.to] = dist[v] + e.cost;
		Q.push(State(e.to,dist[e.to]));
	    }
	}
    }
    return INF;
}
 
void init(){
    for(int i = 0 ; i < MAX_P ; i++){
	G[i].clear();
    }
}
 
int main(){
    int N;
    while(cin >> N, N){
	init();
	Polygon b[MAX_N];
	for(int i = 0 ; i < N ; i++){
	    int M;
	    cin >> M; b[i].resize(M);
	    for(int j = 0 ; j < M ; j++){
		cin >> b[i][j].x >> b[i][j].y;
	    }
	}
	Point s,t;
	Line l;
	cin >> s.x >> s.y >> t.x >> t.y;
	cin >> l.s.x >> l.s.y >> l.t.x >> l.t.y;
	int n = -1;
	for(int i = 0 ; i < N ; i++){
	    if(containPP(b[i],s) != 0){
		n = i;
		L = b[n];
		break;
	    }
	}
	int rn = -1;
	Point rs = reflection(l,s);
	for(int i = 0 ; i < N ; i++){
	    if(containPP(b[i],rs) != 0){
		rn = i;
		R = b[rn];
		break;
	    }
	}
	Point rt = reflection(l,t);
	if(n == -1 || rn == -1 ||
	   containPP(R,rt) == 0){
	    cout << "impossible" << endl;
	    continue;
	}
 
	int size = L.size();
	int rsize = R.size();
	int src,dst;
	for(int i = 0 ; i < size ; i++){
	    L[i] = reflection(l,L[i]);
	}
	set<Point> st;
	for(int i = 0 ; i < size ; i++){
	    if(st.find(L[i]) == st.end()){
		st.insert(L[i]);
	    }
	}
 
	for(int i = 0 ; i < rsize ; i++){
	    if(st.find(R[i]) == st.end()){
		st.insert(R[i]);
	    }
	}
	s = reflection(l,s);
	t = reflection(l,t);
	if(st.find(s) == st.end()) st.insert(s);
	if(st.find(t) == st.end()) st.insert(t);
	vector<Point> vec;
	for(auto it = st.begin() ; it != st.end() ; ++it){
	    vec.push_back(*it);
	}
	size = vec.size();
	for(int i = 0 ; i < size ; i++){
	    for(int j = i+1 ; j < size ; j++){
		Segment seg(vec[i],vec[j]);
		if(containPS(L,seg) && containPS(R,seg)){
		    double d = dist(vec[i],vec[j]);
		    G[i].push_back(Edge(j,d));
		    G[j].push_back(Edge(i,d));
		}
	    }
	    if(s == vec[i]) src = i;
	    if(t == vec[i]) dst = i;
	}
	double res = dijkstra(src,dst);
	if(res == INF){
	    cout << "impossible" << endl;
	}else{
	    printf("%.10f\n",res);
	}
    }
    return 0;
}
