#include <bits/stdc++.h>

using namespace std;

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

double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }

pair<Point,double> smallest_enclosing_circle(const vector<Point> &pts){
    Point p(0,0);
    for(int i = 0 ; i < (int)pts.size() ; i++){
	p = p + pts[i];
    }
    p = p * (1. / pts.size());
    double d = 0.5;
    for(int k = 1 ; k <= 30 ; k++){
	for(int i = 0 ; i < 10 ; i++){
	    int s = 0;
	    for(int j = 0 ; j < (int)pts.size() ; j++){
		if(abs(pts[j] - p) > abs(pts[s] - p)){
		    s = j;
		}
	    }
	    p = p + (pts[s] - p) * d;
	}
	d *= 0.5;
    }
    double max_dist = 0;
    for(int i = 0 ; i < (int)pts.size() ; i++){
	if(abs(pts[i] - p) > max_dist){
	    max_dist = abs(pts[i]-p);
	}
    }
    return make_pair(p,max_dist);
}
