#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS (1e-6)
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define MAX 252
#define INF (1e9)
#define PI acos(-1)
 
struct Point{
    double x,y;
 
    Point(){}
    Point(double x,double y) : x(x),y(y) {}
 
    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k,y*k); }
    Point operator / (const double &k)const{ return Point(x/k,y/k); }
    bool operator < (const Point &p)const{ return x != p.x ? x < p.x : y < p.y; }
    bool operator == (const Point &p)const{ return (x == p.x && y == p.y); }
};
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
double dist(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
 
double toAng(double rad){ return rad*180/PI; }
 
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
 
double getAngle(const Point &a,const Point &b,const Point &c){
    Vector v1 = b-a, v2 = c-b;
    double aa = atan2(v1.y,v1.x),ba = atan2(v2.y,v2.x);
    if(aa > ba) swap(aa,ba);
    double ang = toAng(ba - aa);
    return min(ang,360-ang);
}
 
struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};
 
bool isIntersectSP(const Segment &s,const Point &p){
    return (ccw(s.s,s.t,p) == 0);
}
 
bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return (ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
            ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0);
}
 
Point crosspointSS(const Segment &a,const Segment &b){
    Vector va = a.t-a.s, vb = b.t-b.s;
    double d = cross(vb,va);
    if(abs(d) < EPS) return b.s;
    return a.s+va*cross(vb,b.t-a.s)*(1.0/d);
}
 
typedef vector<vector<int> > Graph;
 
Graph segmentArrangement(vector<Segment> &segs,vector<Point> &ps){
    Graph G;
    int N = segs.size();
    ps.clear();
 
    for(int i = 0 ; i < N ; i++){
        ps.push_back(segs[i].s);
        ps.push_back(segs[i].t);
        for(int j = i+1 ; j < N ; j++){
            Vector a = segs[i].t - segs[i].s;
            Vector b = segs[j].t - segs[j].s;
            if(equal(cross(a,b),0)) continue;
            if(isIntersectSS(segs[i],segs[j])){
                ps.push_back(crosspointSS(segs[i],segs[j]));
            }
        }
    }
    sort(ps.begin(),ps.end());
    ps.erase(unique(ps.begin(),ps.end()),ps.end());
 
    int N2 = ps.size();
    G.resize(N2);
    for(int i = 0 ; i < N ; i++){
        vector<int> vec;
        for(int j = 0 ; j < N2 ; j++){
            if(isIntersectSP(segs[i],ps[j])){
                vec.push_back(j);
            }
        }
        sort(vec.begin(),vec.end());
        for(int j = 0 ; j < (int)vec.size()-1 ; j++){
            int u = vec[j], v = vec[j+1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    return G;
}
 
struct State{
    double w;
    int p,n;
    State(){}
    State(double w,int p,int n) :
        w(w),p(p),n(n) {}
     
    bool operator < (const State &s)const{
        return w > s.w;
    }
};
 
double dijkstra(Graph &G,Point &s,Point &t,vector<Point> &ps){
    int idx = -1;
    for(int i = 0 ; i < (int)ps.size() ; i++){
        if(ps[i] == s){
            idx = i;
        }
    }
    double d[MAX][MAX];
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            d[i][j] = INF;
        }
    }
    priority_queue<State> Q;
    for(int i = 0 ; i < (int)G[idx].size() ; i++){
        int to = G[idx][i];
        Q.push(State(0,idx,to));
        d[idx][to] = 0;
    }
    while(!Q.empty()){
        State st = Q.top(); Q.pop();
        int p = st.p,n = st.n;
        double w = st.w;
        if(lt(d[p][n],w)) continue;
        Point p1 = ps[p],p2 = ps[n];
        if(p2 == t) return d[p][n];
        for(int i = 0 ; i < (int)G[n].size() ; i++){
            int to = G[n][i];
            if(p == to) continue;
            Point p3 = ps[to];
            double ncost = w + getAngle(p1,p2,p3);
            if(lt(ncost,d[n][to])){
                d[n][to] = ncost;
                Q.push(State(d[n][to],n,to));
            }
        }
    }
    return INF;
}
 
int main(){
    int N;
    while(cin >> N, N){
        Point s,t;
        vector<Segment> segs(N);
        for(int i = 0 ; i < N ; i++){
            cin >> segs[i].s.x >> segs[i].s.y;
            cin >> segs[i].t.x >> segs[i].t.y;
        }
        cin >> s.x >> s.y >> t.x >> t.y;
        vector<Point> ps;
        Graph G = segmentArrangement(segs,ps);
        double res = dijkstra(G,s,t,ps);
        if(res == INF){
            cout << -1 << endl;
        }else{
            printf("%.12f\n",res);
        }
    }
    return 0;
}
