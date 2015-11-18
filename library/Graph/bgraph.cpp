/*
  頂点数nの無向グラフが与えられる。隣接している頂点同士が異なる色になるように、頂点に色を塗っていく。
  2色以内ですべての頂点を塗ることができるか判定せよ。多重辺やループはないものとする。

  O(VE)
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_V 1000

//入力
vector<int> G[MAX_V];  //グラフ
int V;                 //頂点数

int color[MAX_V];      //頂点iの色(1 or -1)

//頂点を1と-1で塗っていく
bool dfs(int v,int c){
  color[v] = c;   //頂点vをcで塗る
  for(int i = 0 ; i < (int)G[v].size() ; i++){
    //隣接している頂点が同じ色ならfalse
    if(color[G[v][i]] == c){ return false; }
    //隣接している頂点がまだ塗られていないなら-cで塗る
    if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)){
      return false;
    }
  }
  //全ての頂点を塗ることができた
  return true;
}

void solve(){
  for(int i = 0 ; i < V ; i++){
    if(color[i] == 0){
      //まだ頂点iが塗られていないなら1で塗る
      if(!dfs(i,1)){
        puts("No");
        return;
      }
    }
  }
  puts("Yes");
}
