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
  bool operator < (const Point &p)const{ return x != p.x ? x < p.x : y < p.y; }
};

Point operator * (const Point &a,const Point &b){ return Point(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }

double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }

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
  if(cross(a,b) > EPS){ return COUNTER_CLOCKWISE; }
  if(cross(a,b) < -EPS){ return CLOCKWISE; }
  if(dot(a,b) < -EPS){ return ONLINE_BACK; }
  if(norm(a) < norm(b)){ return ONLINE_FRONT; }
  return ON_SEGMENT;
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

double distanceLP(const Line &l,const Point &p){
  return abs(p-projection(l,p));
}

struct Circle{
  Point p;
  double r;
  Circle(){}
  Circle(Point p,double r) : p(p),r(r) {}
};

vector<Point> crosspointCL(const Circle &c,const Line &l){
  vector<Point> res;
  double d = distanceLP(l,c.p);
  if(le(d,c.r)){
    Point p = projection(l,c.p);
    Vector v = (l.t - l.s) / abs(l.t - l.s);
    d = sqrt(c.r*c.r-d*d);
    res.push_back(p - v*d);
    res.push_back(p + v*d);
  }
  return res;
}

int main(){
  Circle c;
  int Q;
  cin >> c.p >> c.r >> Q;
  while(Q--){
    Line l;
    cin >> l.s >> l.t;
    vector<Point> cp = crosspointCL(c,l);
    sort(cp.begin(),cp.end());
    printf("%.10f %.10f %.10f %.10f\n",cp[0].x,cp[0].y,cp[1].x,cp[1].y);
  }
  return 0;
}
