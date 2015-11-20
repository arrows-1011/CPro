#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 30
#define EPS 1e-9
 
class Point{
public:
    double x,y,z;
    Point(){}
    Point(double x,double y,double z) : x(x),y(y),z(z) {}
};
 
double getDistance(const Point &a,const Point &b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}
 
istream &operator >> (istream &is,Point &p){
    is >> p.x >> p.y >> p.z;
    return is;
}
 
int main(){
    int N;
    Point point[MAX];
    while(cin >> N, N){
	double x = 0, y = 0, z = 0;
	for(int i = 0 ; i < N ; i++){
	    cin >> point[i];
	    x += point[i].x;
	    y += point[i].y;
	    z += point[i].z;
	}
	x /= N; y /= N; z /= N;
	int pos = -1;
	double d = 0.8, ans = 0;
	Point p(x,y,z);
	while(d > EPS){
	    for(int i = 0 ; i < 150 ; i++){
		ans = 0;
		for(int j = 0 ; j < N ; j++){
		    double dist = getDistance(p,point[j]);
		    if(ans < dist){
			ans = dist;
			pos = j;
		    }
		}
		p.x += (point[pos].x-p.x)*d;
		p.y += (point[pos].y-p.y)*d;
		p.z += (point[pos].z-p.z)*d;
	    }
	    d /= 2;
	}
	printf("%.6f\n",ans);
    }
    return 0;
}
