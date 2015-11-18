#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
#define LIMIT 16
typedef vector<int> Vec;
 
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
int res;
bool flg;
 
bool inField(int y,int x){
  return 0 <= y && y < 3 && 0 <= x && x < 3; 
}
 
bool check(Vec &vec){
  for(int i = 0 ; i < 8 ; i++){
    if(vec[i] != i+1) return false;
  }
  return true;
}
 
void solve(Vec &start,int z,map<Vec,int> &cost){
  queue<Vec> Q;
  queue<int> zero;
  Q.push(start); zero.push(z);
  cost[start] = 0;
   
  while(!Q.empty()){
    Vec now = Q.front(); Q.pop();
    int pos = zero.front(); zero.pop();
    int x = pos % 3, y = pos / 3;
    if(!flg && check(now)){
      res = cost[now];
      return;
    }
    if(cost[now] == LIMIT) break;
    for(int i = 0 ; i < 4 ; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(!inField(ny,nx)) continue;
      vector<int> next = now;
      swap(next[pos],next[ny*3+nx]);
      if(!cost.count(next)){
        cost[next] = cost[now] + 1;
        Q.push(next);
        zero.push(ny*3+nx);
      }
    }
  }
}
 
int main(){
  int z = -1;
  vector<int> start(9),goal(9);
  for(int i = 0 ; i < 9 ; i++){
    cin >> start[i];
    goal[i] = i+1;
    if(start[i] == 0) z = i;
  }
  goal[8] = 0;
  res = INF; flg = false;
  map<Vec,int> s2v,g2v;
  solve(start,z,s2v);
  if(res == INF){
    flg = true;
    solve(goal,8,g2v);
  }
  map<Vec,int>::iterator s,g;
  for(s = s2v.begin() ; s != s2v.end() ; ++s){
    if(g2v[s->first]){
      res = min(res,s->second+g2v[s->first]);
    }
  }
  cout << res << endl;
  return 0;
}
