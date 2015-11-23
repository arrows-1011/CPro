#include <bits/stdc++.h>
 
using namespace std;
 
int N,M,c,d;
bool v1[110][110],v2[110];
vector<int> G[110];
 
void dfs(int x){
    if(v2[x]) return; v2[x] = true;
    c++;
    for(int i = 0 ; i < G[x].size() ; i++){
	if(v1[x][G[x][i]]) continue;
	v1[x][G[x][i]] = v1[G[x][i]][x] = true; d++;
	dfs(G[x][i]);
    }
}
 
int main(){
    int a,b;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
	cin >> a >> b; a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }
    int cnt = 0;
    memset(v1,false,sizeof(v1));
    memset(v2,false,sizeof(v2));
    for(int i = 0 ; i < N ; i++){
	if(v2[i]) continue;
	c = d = 0;
	dfs(i);
	if(c == d+1) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
