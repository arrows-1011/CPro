#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
#define INF 1e9
 
int V;
struct State{
    int x, y;
};
 
vector<State> vec;
 
double check(State a, State b){
    return sqrt(pow((a.x-b.x),2.) + pow(a.y-b.y,2.));
}
 
double dist[MAX];
bool used[MAX];
int prev[MAX];
double cost[MAX][MAX];
 
void dijkstra(int s, int t){
    fill(dist, dist+MAX, INF);
    memset(used,false,sizeof(used));
    memset(prev,-1,sizeof(prev));
    dist[s] = 0;
 
    while(true){
	int v = -1;
	for(int u = 0 ; u < V ; u++){
	    if(!used[u] && (v == -1 || 
			    dist[u] < dist[v])){
		v = u;
	    }
	}
 
	if(v == -1){
	    break;
	}else{
	    used[v] = true;
	}
 
	for(int u = 0 ; u < V ; u++){
	    if(dist[u] > dist[v] + cost[u][v] && cost[u][v] <= 50){
		dist[u] = dist[v] + cost[u][v];
		prev[u] = v;
	    }
	}
    }
 
    if(dist[t] == INF){
	cout << "NA" << endl;
    }else{
	vector<int> path;
	for(int i = t ; i != -1 ; i = prev[i]){
	    path.push_back(i);
	}
	reverse(path.begin(), path.end());
     
	int len = path.size();
	for(int i = 0 ; i < len ; i++){
	    cout << path[i]+1 << (i == len-1 ? '\n' : ' ');
	}
    }
}
 
int main(){
    int n, start, goal, num;
    State s;
 
    while(cin >> V, V){
	State distance[MAX];
 
	vec.clear();
	fill(cost[0],cost[V],INF);
	for(int i = 0 ; i < V ; i++){
	    cin >> num >> s.x >> s.y;
	    vec.push_back(s);
	    distance[num-1] = s;
	}
 
	for(int i = 0 ; i < V-1 ; i++){
	    for(int j = i+1 ; j < V ; j++){
		cost[i][j] = cost[j][i] = 
		    check(distance[i],distance[j]);
	    }
	}
  
	cin >> n;
	for(int i = 0 ; i < n ; i++){
	    cin >> start >> goal;
	    start--, goal--;
	    dijkstra(start, goal);
	}
    }
    return 0;
}
