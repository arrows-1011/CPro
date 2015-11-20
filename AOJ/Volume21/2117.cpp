#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
#define MAX 15
#define INF 1e9
 
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y) : x(x), y(y) {}
};
 
struct Segment{
    Point s,t;
    Segment(){}
    Segment(Point s,Point t) : s(s), t(t) {}
};
 
int N;
double dp[1<<MAX][MAX][2];
Segment Seg[MAX];
double d[MAX];
 
double getDistance(Point &p1,Point &p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
 
double solve(int S,int now,bool st){
    if((1<<N)-1 == S){
	if(st){
	    return dp[S][now][st] = d[now];
	}else{
	    return dp[S][now][st] = d[now];
	}
    }
    if(dp[S][now][st] != INF){
	return dp[S][now][st];
    }
    double res = INF;
    for(int i = 0 ; i < N ; i++){
	if(S >> i & 1) continue;
	if(st){
	    res = min(res,solve(S|(1<<i),i,true) + d[now] + getDistance(Seg[now].t,Seg[i].s));
	    res = min(res,solve(S|(1<<i),i,false) + d[now] + getDistance(Seg[now].t,Seg[i].t));     
	}else{
	    res = min(res,solve(S|(1<<i),i,true) + d[now] + getDistance(Seg[now].s,Seg[i].s));
	    res = min(res,solve(S|(1<<i),i,false) + d[now] + getDistance(Seg[now].s,Seg[i].t));   
	}
    }
    return dp[S][now][st] = res;
}
 
int main(){
    int Tc = 1;
    while(cin >> N, N){
	for(int i = 0 ; i < N ; i++){
	    cin >> Seg[i].s.x >> Seg[i].s.y >> Seg[i].t.x >> Seg[i].t.y;
	    d[i] = getDistance(Seg[i].s,Seg[i].t);
	}
	for(int i = 0 ; i < (1<<MAX) ; i++){
	    for(int j = 0 ; j < MAX ; j++){
		for(int k = 0 ; k < 2 ; k++){
		    dp[i][j][k] = INF;
		}
	    }
	}
	double res = INF;
	for(int i = 0 ; i < N ; i++){
	    res = min(res,solve(1<<i,i,true));
	    res = min(res,solve(1<<i,i,false));
	}
	printf("Case %d: %.5f\n",Tc++,res);
    }
    return 0;
}
