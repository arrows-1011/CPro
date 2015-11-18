#include <bits/stdc++.h>

using namespace std;

#define LIMIT 45
#define INF 1e9

struct State{
  int z;
  int field[16];
};


int ans;
bool can;
State s,goal;
const int dx[4] = {0,-1,1,0};
const int dy[4] = {-1,0,0,1};

bool inField(int y,int x){
  return 0 <= y && y < 4 && 0 <= x && x < 4;
}

int Heuristic(){
  int res = 0;
  for(int i = 0 ; i < 16 ; i++){
    int pos = goal.field[i];
    if(pos == 0){
      continue;
    }
    for(int j = 0 ; j < 16 ; j++){
      if(pos == s.field[j]){
        res += abs(i/4-j/4) + abs(i%4-j%4);
      }
    }
  }
  return res;
}

int dfs(int z,int depth,int d){
  int h = Heuristic();
  if(depth + h > LIMIT){
    return INF;
  }
  if(h == 0){
    can = true;
    return depth;
  }
  int res = INF;
  for(int i = 0 ; i < 4 ; i++){
    if(i + d == 3){
      continue;
    }
    int nx = z%4 + dx[i], ny = z/4 + dy[i];
    if(!inField(ny,nx)){
      continue;
    }
    int next = ny*4 + nx;
    swap(s.field[z],s.field[next]);
    int nd = dfs(next,depth+1,i);
    if(can){
      return nd;
    }
    res = min(res,nd);
    swap(s.field[z],s.field[next]);    
  }
  return res;
}


int IDAstar(){
  ans = Heuristic();
  can = false;
  
  while(!can && ans > LIMIT){
    ans = min(ans,dfs(s.z,0,-1));
  }
  return ans;
}

int main(){
  for(int i = 0 ; i < 16 ; i++){
    goal.field[i] = i+1;
    cin >> s.field[i];
    if(s.field[i] == 0){
      s.z = i;
    }
  }
  goal.field[15] = 0;
  goal.z = 15;
  cout << IDAstar() << endl;
  return 0;
}
