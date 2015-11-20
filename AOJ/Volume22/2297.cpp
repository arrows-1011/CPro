#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
typedef pair<int,int> pii;
 
int N,C[4][4];
pii stamp[16];
 
inline int stp(int x,int y,int px,int py,int c,int S){
    for(int i = max(0,py) ; i < min(py+y,4) ; i++){
	for(int j = max(0,px) ; j < min(px+x,4) ; j++){
	    int b = i*4+j;
	    if(C[i][j] == c){
		if((S >> b) & 1) continue;
		S |= (1<<b);
	    }else{
		if((S >> b) & 1){
		    S -= (1<<b);
		}
	    }
	}
    }
    return S;
}
 
int solve(){
    queue<int> Q;
    Q.push(0);
    int dist[1<<16];
    fill(dist,dist+(1<<16),INF);
    dist[0] = 0;
 
    while(!Q.empty()){
	int S = Q.front(); Q.pop();
	if(S == (1<<16)-1){
	    return dist[S];
	}
	for(int i = 0 ; i < N ; i++){
	    pii p = stamp[i];
	    int x = p.second, y = p.first;
	    for(int j = 0 ; j < 3 ; j++){
		for(int px = -x+1 ; px < 4 ; px++){
		    for(int py = -y+1 ; py < 4 ; py++){
			int nS = stp(x,y,px,py,j,S);
			if(dist[S]+1 < dist[nS]){
			    dist[nS] = dist[S] + 1;
			    Q.push(nS);
			}
		    }
		} 
	    }
	}
    }
    return -1;
}
 
int change(char ch){
    if(ch == 'R') return 0;
    if(ch == 'B') return 1;
    return 2;
}
 
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> stamp[i].first >> stamp[i].second;
    }
    char in;
    for(int i = 0 ; i < 4 ; i++){
	for(int j = 0 ; j < 4 ; j++){
	    cin >> in;
	    C[i][j] = change(in);
	}    
    }
    cout << solve() << endl;
    return 0;
}
