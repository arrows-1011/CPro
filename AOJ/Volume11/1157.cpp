#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-8
#define equal(a,b) (fabs(a-b) < EPS)

struct Point{
    double x,y;

    Point(){}
    Point(double x,double y) : x(x),y(y) {}

    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k,y*k); }
};

double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }

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

struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s),t(t) {}
};

Point projection(const Segment &s,const Point &p){
    Vector b = s.t-s.s;
    double t = dot(p-s.s,b)/norm(b);
    return s.s+b*t;
}

bool isIntersectSP(const Segment &s,const Point &p){
    return (ccw(s.s,s.t,p) == 0);
}

bool isIntersectSS(const Segment &a,const Segment &b){
    Point s[2] = {a.s,a.t}, t[2] = {b.s,b.t};
    return (ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
            ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0);
}

double distanceSP(const Segment &s,const Point &p){
    Point r = projection(s,p);
    if(isIntersectSP(s,r)) return abs(r-p);
    return min(abs(s.s-p),abs(s.t-p));
}

double distanceSS(const Segment &a,const Segment &b){
    if(isIntersectSS(a,b)) return 0;
    return min(min(distanceSP(a,b.s),distanceSP(a,b.t)),
           min(distanceSP(b,a.s),distanceSP(b,a.t)));
}

struct Block{
    Point a,b;
    double h;
    Block(){}
    Block(Point &a,Point &b,double h) :
        a(a),b(b),h(h) {}
};

istream &operator >> (istream &is,Point &p){ 
    return is >> p.x >> p.y;
}

double calc(double a,double b){
    return sqrt(a*a+b*b);
}

bool c(double r,Segment &p,vector<Block> &v){
    for(int i = 0 ; i < (int)v.size() ; i++){
        Point a = v[i].a,b = v[i].b;
        Point c(a.x,b.y),d(b.x,a.y);
        Segment s1(a,c),s2(a,d),s3(c,b),s4(d,b);
        double dst[] = {
            distanceSS(p,s1),distanceSS(p,s2),
            distanceSS(p,s3),distanceSS(p,s4)
        };
 
        if(r < v[i].h){
            if(!(r < dst[0] && r < dst[1] &&
                 r < dst[2] && r < dst[3])){
                return 0;
            }
        }else{
            double nh = r - v[i].h;
            if(!(r < calc(nh,dst[0]) && r < calc(nh,dst[1]) &&
                 r < calc(nh,dst[2]) && r < calc(nh,dst[3]))){
                return 0;
            }
        }
    }
    return 1;
}

bool check(Segment &p,vector<Block> &v){
    for(int i = 0 ; i < (int)v.size() ; i++){
        Point a = v[i].a,b = v[i].b;
        Point c(a.x,b.y),d(b.x,a.y);
        Segment s1(a,c),s2(a,d),s3(c,b),s4(d,b);
        if((a.x < p.s.x && p.s.x < b.x &&
            a.y < p.s.y && p.s.y < b.y) ||
           (a.x < p.t.x && p.t.x < b.x &&
            a.y < p.t.y && p.t.y < b.y)){
            return 1;
        }
        if(isIntersectSS(p,s1)) return 1;
        if(isIntersectSS(p,s2)) return 1;
        if(isIntersectSS(p,s3)) return 1;
        if(isIntersectSS(p,s4)) return 1;
    }
    return 0;
}

int main(){
    int N;
    while(cin >> N,N){
        Segment seg;
        cin >> seg.s >> seg.t;
        vector<Block> v(N);
        for(int i = 0 ; i < N ; i++){
            cin >> v[i].a >> v[i].b >> v[i].h;
        }
        if(check(seg,v)){
            cout << 0 << endl;
            continue;
        }
        double l = 0,r = 1001;
        for(int i = 0 ; i < 100 ; i++){
            double mid = (l + r) / 2;
            if(c(mid,seg,v)){
                l = mid;
            }else{
                r = mid;
            }
        }
        printf("%.10f\n",l);
    }
    return 0;
}
