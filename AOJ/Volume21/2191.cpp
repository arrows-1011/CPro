#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 1010
  
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y) : x(x),y(y) {}
};
  
int N,X,Y;
vector<int> G[MAX];
  
double getDist(Point &a,Point &b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
  
void init(){
    for(int i = 0 ; i < MAX ; i++){
	G[i].clear();
    }  
}
  
void solve(){
    int d[MAX] = {0};
    queue<int> Q; Q.push(0);
    bool can = true;
   
    while(!Q.empty()){
	int v = Q.front(); Q.pop();
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    int to = G[v][i];
	    if(d[to] == 0){
		d[to] = d[v] + 1;
		if(v > 0 && X > Y) can = false;
		Q.push(to);
	    }
	}
    }
   
    if(can){
	cout << *max_element(d+1,d+N+1)*X << endl;
    }else{
	cout << "You're always welcome!" << endl;
    }
}
  
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	init();
	Point sp;
	vector<Point> p;
	cin >> N >> X >> Y;
	cin >> sp.x >> sp.y;
	p.resize(N);
	for(int i = 0 ; i < N ; i++){
	    cin >> p[i].x >> p[i].y;
	    if(getDist(sp,p[i]) <= 10){
		G[0].push_back(i+1);
	    }
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(i == j) continue;
		if(getDist(p[i],p[j]) <= 50){
		    G[i+1].push_back(j+1);
		}
	    }
	}
	solve();
    }
    return 0;
}
