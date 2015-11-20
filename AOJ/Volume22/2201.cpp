#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (lt(a,b) || equal(a,b))
 
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
double abs(const Point &p){ return sqrt(norm(p)); }
 
Point rotate90(const Point &p){ return Point(-p.y,p.x); }
 
struct Line{
    Point s,t;
    Line(){}
    Line(Point s,Point t) : s(s),t(t) {}
};
 
Point projection(const Line &l,const Point &p){
    Point b = l.t-l.s;
    double t = dot(p-l.s,b)/norm(b);
    return l.s+b*t;
}
 
double distanceLP(const Line &l,const Point &p){
    return abs(p-projection(l,p));
}
 
struct Circle{
    Point p;
    double r;
    Circle(){}
    Circle(Point p,double r) : p(p),r(r) {}
};
 
vector<Point> tangentCP(const Circle &c,const Point &p){
    double x = norm(p - c.p);
    double d = x - c.r*c.r;
    if(d < -EPS) return vector<Point>();
    d = max(d, 0.0);
    Point p1 = (p-c.p)*(c.r*c.r/x);
    Point p2 = rotate90((p-c.p)*(-c.r*sqrt(d)/x));
    vector<Point> res;
    res.push_back(c.p + p1 - p2);
    res.push_back(c.p + p1 + p2);
    return res;
}
 
vector<Line> tangentCC(const Circle &a,const Circle &b){
    vector<Line> res;
    vector<Point> ps,qs;
    if(abs(b.p-a.p) < EPS) return res;
    if(abs(a.r - b.r) < EPS){
        Point dir = b.p-a.p;
        dir = rotate90(dir*(a.r/abs(dir)));
        res.push_back(Line(a.p+dir,b.p+dir));
        res.push_back(Line(a.p-dir,b.p-dir));
    }else{
        Point p = a.p*(-b.r) + b.p*a.r;
        p = p*(1.0/(a.r-b.r));
        ps = tangentCP(a,p);
        qs = tangentCP(b,p);
        int n = ps.size(), m = qs.size();
        for(int i = 0 ; i < min(n,m) ; i++){
            res.push_back(Line(ps[i],qs[i]));
        }
    }
    Point p = a.p*b.r + b.p*a.r;
    p = p*(1.0/(a.r+b.r));
    ps = tangentCP(a,p);
    qs = tangentCP(b,p);
    int n = ps.size(), m = qs.size();
    for(int i = 0 ; i < min(n,m) ; i++){
        res.push_back(Line(ps[i],qs[i]));
    }
    return res;
}
 
struct Data{
    Circle c;
    double m;
    Data(){}
};
 
vector<Line> getTCC(const Point &p1,double r1,
                    const Point &p2,double r2){
    Circle c1(p1,r1),c2(p2,r2);
    vector<Line> res = tangentCC(c1,c2);
    return res;
}
 
int main(){
    int N;
    while(cin >> N, N){
        vector<Data> v(N);
        for(int i = 0 ; i < N ; i++){
            cin >> v[i].c.p.x >> v[i].c.p.y >> v[i].c.r >> v[i].m;
            v[i].m += v[i].c.r;
        }
        vector<Line> lines;
        for(int i = 0 ; i < N ; i++){
            for(int j = i+1 ; j < N ; j++){
                Point p1 = v[i].c.p, p2 = v[j].c.p;
                double r1 = v[i].c.r, r2 = v[j].c.r;
                double m1 = v[i].m, m2 = v[j].m;
                vector<Line> l;
                l = getTCC(p1,r1,p2,r2);
                lines.insert(lines.end(),l.begin(),l.end());
                l = getTCC(p1,r1,p2,m2);
                lines.insert(lines.end(),l.begin(),l.end());
                l = getTCC(p1,m1,p2,r2);
                lines.insert(lines.end(),l.begin(),l.end());
                l = getTCC(p1,m1,p2,m2);
                lines.insert(lines.end(),l.begin(),l.end());
            }
        }
        int res = 1;
        for(int i = 0 ; i < (int)lines.size() ; i++){
            int cnt = 0;
            for(int j = 0 ; j < N ; j++){
                double d = distanceLP(lines[i],v[j].c.p);
                if(le(v[j].c.r,d) && le(d,v[j].m)) cnt++;
            }
            res = max(res,cnt);
        }
        cout << res << endl;
    }
    return 0;
}
