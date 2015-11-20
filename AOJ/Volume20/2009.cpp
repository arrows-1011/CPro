#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-10
#define equal(a,b) (fabs(a-b) < EPS)
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
 
double dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
double cross(const Point &a,const Point &b){ return a.x*b.y - b.x*a.y; }
double norm(const Point &p){ return dot(p,p); }
double abs(const Point &p){ return sqrt(norm(p)); }
 
istream &operator >> (istream &is,Point &p){ 
    return is >> p.x >> p.y;
}
 
typedef Point Vector;
 
struct Line{
    Point s,t;
    Line(){}
    Line(Point s,Point t) : s(s),t(t) {}
};
 
bool isIntersectLL(const Line &a,const Line &b){
    return abs(cross(a.t-a.s,b.t-b.s)) > EPS
	|| abs(cross(a.t-a.s,b.t-b.s)) < EPS;
}
 
Point crosspointLL(const Line &a,const Line &b){
    Vector va = a.t-a.s, vb = b.t-b.s;
    double d = cross(vb,va);
    return a.s+va*cross(vb,b.t-a.s)*(1.0/d);
}
 
int main(){
    int N;
    while(cin >> N,N){
	vector<Line> l(N);
	for(int i = 0 ; i < N ; i++){
	    cin >> l[i].s >> l[i].t;
	}
	int div = 1;
	for(int i = 0 ; i < N ; i++){
	    int cp = 0;
	    vector<Point> used;
	    for(int j = 0 ; j < i ; j++){
		if(isIntersectLL(l[i],l[j])){
		    Point p = crosspointLL(l[i],l[j]);
		    bool flg = false;
		    for(int k = 0 ; k < (int)used.size() ; k++){
			Point q = used[k];
			if(equal(p.x,q.x) && equal(p.y,q.y)){
			    flg = true;
			    break;
			}
		    }
		    if(flg) continue;
		    used.push_back(p);
		    if(lt(-100,p.x) && lt(p.x,100) &&
		       lt(-100,p.y) && lt(p.y,100)){
			cp++;
		    }
		}
	    }
	    div += cp+1;
	}
	cout << div << endl;
    }
    return 0;
}
