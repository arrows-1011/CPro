#include <bits/stdc++.h>
 
using namespace std;
 
#define NOTFOUND -1
typedef vector<int> Vec;
 
bool check(Vec &p){
    int t = p[0];
    for(int i = 0 ; i < 8 ; i++){
	if(t != p[i+1]) return false;
    }
    if(p[9] != p[10] || p[9] != p[11] || p[10] != p[11]) return false;
    if(p[12] != p[13] || p[12] != p[14] || p[13] != p[14]) return false;
    if(p[15] != p[16] || p[15] != p[17] || p[16] != p[17]) return false;
    if(p[18] != p[19] || p[18] != p[20] || p[19] != p[20]) return false;
    t = p[21];
    for(int i = 0 ; i < 8 ; i++){
	if(t != p[22+i]) return false;
    }
    return true;
}
 
void roll(int N,Vec &v){
    if(N == 0){
	swap(v[0],v[23]);
	swap(v[3],v[26]);
	swap(v[6],v[29]);
	swap(v[9],v[20]);
	swap(v[15],v[17]);
    }else if(N == 1){
	swap(v[2],v[21]);
	swap(v[5],v[24]);
	swap(v[8],v[27]);
	swap(v[11],v[18]);
	swap(v[12],v[14]);
    }else if(N == 2){
	swap(v[0],v[27]);
	swap(v[1],v[28]);
	swap(v[2],v[29]);
	swap(v[14],v[15]);
	swap(v[18],v[20]);
    }else if(N == 3){
	swap(v[6],v[21]);
	swap(v[7],v[22]);
	swap(v[8],v[23]);
	swap(v[12],v[17]);
	swap(v[9],v[11]);
    }
}
 
int solve(Vec &puzzle){
    map<Vec,int> cost;
    queue<Vec> Q;
    cost[puzzle] = 0;
    Q.push(puzzle);
    while(!Q.empty()){
	Vec now = Q.front(); Q.pop();
	if(check(now)) return cost[now];
	for(int i = 0 ; i < 4 ; i++){
	    Vec next = now;
	    roll(i,next);
	    if(!cost.count(next)){
		cost[next] = cost[now] + 1;
		Q.push(next);
	    }
	}
    }
    return NOTFOUND;
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	Vec puzzle(30);
	for(int i = 0 ; i < 30 ; i++){
	    cin >> puzzle[i];
	}
	cout << solve(puzzle) << endl;
    }
    return 0;
}
