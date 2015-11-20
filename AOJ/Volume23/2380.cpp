#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
 
inline void moveState(vector<int> &v,int p){
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,-1,0,1};
    bool tmp[16][4],use[16][4] = {{0}};
    fill(use[p],use[p]+4,1);
    bool update = 1;
    while(update){
	vector<int> next = v;
	update = 0;
	memset(tmp,0,sizeof(tmp));
	for(int i = 0 ; i < 16 ; i++){
	    for(int j = 0 ; j < 4 ; j++){
		if(!use[i][j]) continue;
		int nx = i%4 + dx[j], ny = i/4 + dy[j];
		int np = nx + 4*ny;
		if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4){
		    continue;
		}
		update = 1;
		if(v[np] > 0) next[np]++;
		else tmp[np][j] = 1;
	    }
	}
	for(int i = 0 ; i < 16 ; i++){
	    if(next[i] >= 5){
		next[i] = 0;
		fill(tmp[i],tmp[i]+4,1);
	    }
	}
	v = next;
	memcpy(use,tmp,64);
    }
}
 
int solve(vector<int> &v,int step){
    if(count(v.begin(),v.end(),0) == 16){
	return step;
    }
    if(step == 5) return INF;
    int res = INF;
    for(int i = 0 ; i < 16 ; i++){
	vector<int> next = v; next[i]++;
	if(next[i] == 5){
	    next[i] = 0;
	    moveState(next,i);
	}
	res = min(res,solve(next,step+1));
    }
    return res;
}
 
int main(){
    vector<int> v(16);
    for(int i = 0 ; i < 16 ; i++){
	cin >> v[i];
    }
    int res = solve(v,0);
    cout << (res < INF ? res : -1) << endl;
    return 0;
}
