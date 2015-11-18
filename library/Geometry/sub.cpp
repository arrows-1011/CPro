#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
#define INF (1e50)

struct Point{
    double x,y;

    Point(){}
    Point(double x,double y) : x(x),y(y) {}
    Point operator + (const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator - (const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator * (const double &k)const{ return Point(x*k,y*k); }
    bool operator < (const Point &p)const{ return x != p.x ? x < p.x : y < p.y; }
};

double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }

typedef vector<Point> Polygon;

bool compare_y(const Point &a,const Point &b){
  return a.y < b.y;
}

double closest_pair(Point *a,int n){
    if(n <= 1) return INF;
    int m = n / 2;
    double x = a[m].x;
    double d = min(closest_pair(a,m),closest_pair(a+m,n-m));
    inplace_merge(a,a+m,a+n,compare_y);

    Polygon b;
    for(int i = 0 ; i < n ; i++){
        if(fabs(a[i].x - x) >= d) continue;
        for(int j = 0 ; j < (int)b.size() ; j++){
            double dx = a[i].x - b[b.size()-j-1].x;
            double dy = a[i].y - b[b.size()-j-1].y;
            if(dy >= d) break;
            d = min(d,sqrt(dx * dx + dy * dy));
        }
        b.push_back(a[i]);
    }
    return d;
}

int main(){
    int N;
    cin >> N;
    Point p[N];
    for(int i = 0 ; i < N ; i++){
        cin >> p[i].x >> p[i].y;
    }
    sort(p,p+N);
    printf("%.12f\n",closest_pair(p,N));
    return 0;
}
