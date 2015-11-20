#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 21
#define EPS 1e-9
#define INF 1e9
 
struct Point{
    double x, y;
}; 
 
int N;
Point h, d, crystal[MAX];
  
double dist(Point a, Point b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
 
bool rec(int S, int v, double total_dist){
    if(S == (1 << N) - 1){
	return true;
    }
    for(int u = 0 ; u < N ; u++){
	if(!(S >> u & 1)){
	    if(total_dist + dist(crystal[v],crystal[u]) >= dist(d, crystal[u])){
		return false;
	    }
	}
    }
    for(int u = 0 ; u < N ; u++){
	if(!(S >> u & 1)){
	    if(rec(S | 1 << u, u, total_dist + dist(crystal[v],crystal[u]))){
		return true;
	    }
	}
    }
}
 
bool solve(){
    for(int i = 0 ; i < N ; i++){
	if(rec(0,i,dist(h,crystal[i]))){
	    return true;
	}
    }  
    return false;
}
  
int main(){
    while(cin >> N >> h.x >> h.y >> d.x >> d.y, (N + h.x + h.y + d.x + d.y)){
	for(int i = 0 ; i < N ; i++){
	    cin >> crystal[i].x >> crystal[i].y;
	}
	cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
