#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (1<<29)
 
int N,M;
 
int bfs(int s,int g){
    queue<int> Q;
    Q.push(s);
    int d[1<<N];
    fill(d,d+(1<<N),INF);
    d[s] = 0;
 
    while(!Q.empty()){
	int S = Q.front(); Q.pop();
	if(S == g) return d[S];
	for(int i = 0 ; i < N-1 ; i++){
	    int nS = S;
	    if(((S >> i) & 1) ^ ((S >> (i+1)) & 1)){
		nS ^= 1<<i; nS ^= 1<<(i+1);
		if(d[S] + 1 < d[nS]){
		    d[nS] = d[S] + 1;
		    Q.push(nS);
		}
	    }
	}
    }
    return INF;
}
 
int main(){
    int in,s,g1,g2,sum;
    s = g1 = g2 = sum = 0;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
	cin >> in;
	s += (in ? (1<<i) : 0);
    }
    for(int i = 0 ; i < M ; i++){
	cin >> in;
	for(int j = 0 ; j < in ; j++){
	    g1 += (i % 2 ? 1<<(sum+j) : 0);
	}
	for(int j = 0 ; j < in ; j++){
	    g2 += (i % 2 ? 0 : 1<<(sum+j)); 
	}
	sum += in;
    }
    cout << min(bfs(s,g1),bfs(s,g2)) << endl;
    return 0;
}
