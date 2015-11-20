#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100001
#define INF (1<<29)
typedef pair<int,int> pii;
 
int field[MAX],N,dist[MAX];
 
bool inField(int x){
    return 0 <= x && x < N;
}
 
int dijkstra(int s){
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(pii(dist[s],s));
    while(!Q.empty()){
	pii p = Q.top(); Q.pop();
	int v = p.second;
	if(dist[v] < p.first) continue;
	if(field[v] == 0){
	    for(int i = 0 ; i < 6 ; i++){
		int next = v+i+1;
		if(!inField(next)) continue;
		if(dist[v] + 1 < dist[next]){
		    dist[next] = dist[v] + 1;
		    Q.push(pii(dist[next],next));
		}
	    }
	}else{
	    int next = v + field[v];
	    if(!inField(next)) continue;
	    if(dist[v] < dist[next]){
		dist[next] = dist[v];
		Q.push(pii(dist[next],next));
	    }
	}
    }
    return dist[N-1];
}
 
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> field[i];
    }
    fill(dist,dist+MAX,INF);
    dist[0] = 0;
    cout << dijkstra(0) << endl;
    return 0;
}
