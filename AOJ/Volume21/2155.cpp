#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 20000
 
struct edge{
    int from, to, cost;
 
    edge(int from = -1, int to = -1, int cost = -1) 
	: from(from), to(to), cost(cost) {}
 
    bool operator < (const edge &e)const{
	return cost < e.cost;
    }
};
 
int main(){
    int N, M, t, s, d;
 
    while(cin >> N >> M , N){
	edge e[MAX];
 
	for(int i = 0 ; i < M ; i++){
	    cin >> t >> s >> d;
	    e[i] = edge(s-1, d-1, t);
	}
     
	sort(e, e+M);
	bool check[MAX] = {false};
	check[0] = true;
 
	for(int i = 0 ; i < M ; i++){
	    if(check[e[i].from]){
		check[e[i].to] = true;
	    }
	}
     
	int ans = 0;
	for(int i = 0 ; i < N ; i++){
	    if(check[i]) ans++;
	}
	cout << ans << endl;
    }
    return 0;
}
