/*
  matは、'.'と'*'で構成されており、
  '.'でできる最大の長方形の面積を求める。
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define MAX_H 1510
#define MAX_W 1510

int H,W;
int mat[MAX_H][MAX_W];

int maximum_rectangle(){
  int res = 0,h[MAX_W] = {0};
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      h[j] = (mat[i][j] == 0 ? h[j] + 1 : 0);
    }
    stack<pii> st;
    st.push(pii(0,W));
    for(int j = 0 ; j <= W ; j++){
      int k = j;
      while(h[j] < st.top().first){
        k = st.top().second;
        res = max(res,st.top().first*(j-k));
        st.pop();
      }
      if(st.top().first < h[j]){
        st.push(pii(h[j],k));
      }
    }
  }
  return res;
}

int main(){
  cin >> H >> W;
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> mat[i][j];
    }
  }
  cout << maximum_rectangle() << endl;
  return 0;
}
