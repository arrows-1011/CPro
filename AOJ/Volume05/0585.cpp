#include <bits/stdc++.h>
   
using namespace std;
   
const int INF = (1<<29);
   
class Point{
public:
    double x,y;
   
    Point(double x = 0, double y = 0):x(x),y(y){}
   
    bool operator < (const Point &a)const{
	if(x != a.x) return x < a.x;
	return y < a.y;
    }
};
   
bool compare(Point a, Point b){
    return a.y < b.y;
}
   
double solve(Point *a, int n){
    if(n <= 1) return INF;
    int m = n / 2;
    double xx = a[m].x;
    double d = min(solve(a,m),solve(a+m,n-m));
    inplace_merge(a,a+m,a+n,compare);
   
    vector<Point> v;
    for(int i = 0 ; i < n ; i++){
	if(fabs(a[i].x - xx) >= d) continue;
	int len = (int)v.size();
	for(int j = 0 ; j < len ; j++){
	    double dx = a[i].x - v[len-j-1].x;
	    double dy = a[i].y - v[len-j-1].y;
   
	    if(dy*dy >= d) break;
	    d = min(d,dx * dx + dy * dy);
	}
	v.push_back(a[i]);
    }
    return d;
}
   
int main(){
    int n;
   
    cin >> n;
    Point p[n];
    for(int i = 0 ; i < n ; i++){
	scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    sort(p,p+n);
    cout << solve(p,n) << endl;
    return 0;
}
