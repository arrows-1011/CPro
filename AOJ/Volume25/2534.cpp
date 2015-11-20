#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 26
 
int res;
bool found;
vector<int> G[MAX_V];
int visited[MAX_V],num[MAX_V];
 
void dfs(int v,int c){
  visited[v] = 0; num[v] = c;
  for(int i = 0 ; i < (int)G[v].size() ; i++){
    int to = G[v][i];
    if(visited[to] == -1){
      dfs(to,c+1);
    }else if(visited[to] == 0){
      res = max(res,num[v]-num[to]+1);
    }
  }
  visited[v] = 1;
}
 
int getLargestCycle(){
  res = 0;
  memset(num,-1,sizeof(num));
  memset(visited,-1,sizeof(visited));
  for(int i = 0 ; i < 26 ; i++){
    if(visited[i] == -1){
      dfs(i,1);
    }
  }
  return res;
}
 
void init(){
    found = false;
    for(int i = 0 ; i < MAX_V ; i++){
        G[i].clear();
    }
}
 
bool valid(string &a, string &b){
    int A = a.size(),B = b.size();
    if(A <= B) return true;
    for(int i = 0 ; i < B ; i++){
        if(a[i] != b[i]) return true;
    }
    return false;
}
 
bool check(vector<string> &v){
    int N = v.size();
    for(int i = 0 ; i < N-1 ; i++){
        if(!valid(v[i],v[i+1])) return false;
        int a = v[i].size(),b = v[i+1].size();
        for(int j = 0 ; j < min(a,b) ; j++){
            if(v[i][j] != v[i+1][j]){
                G[v[i][j]-'a'].push_back(v[i+1][j]-'a');
                break;
            }
        }
    }
    return (getLargestCycle() < 2);
}
 
int main(){
    int N;
    while(cin >> N, N){
        vector<string> v(N);
        for(int i = 0 ; i < N ; i++){
            cin >> v[i];
        }
        init();
        cout << (check(v) ? "yes" : "no") << endl;
    }
    return 0;
}
