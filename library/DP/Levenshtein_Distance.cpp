/*
  Levenshtein Distance(編集距離)とは、
  2つの文字列をs,tとする。以下の3つの操作により、sからtにするための最小回数である。
  1. 挿入: 文字列に1つの文字を挿入する。
  2. 削除: 文字列から1つの文字を削除する。
  3. 置換: 文字列の中の1文字を異なる文字に置き換える。

  incostは挿入のコスト
  rmcostは削除のコスト
  recostは置換のコスト
  何も指定しない場合は全てのコストが1である
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int Levenshtein_Distance(char *s,char *t,
			 int incost = 1,int rmcost = 1,int recost = 1){
    int N = strlen(s),M = strlen(t);
    int dp[N+1][M+1];

    for(int i = 0 ; i <= N ; i++){
	dp[i][0] = i*incost;
    }
    for(int i = 0 ; i <= M ; i++){
	dp[0][i] = i*rmcost;
    }
    for(int i = 1 ; i <= N ; i++){
	for(int j = 1 ; j <= M ; j++){
	    int rcost = (s[i-1] == t[j-1] ? 0 : recost);
	    dp[i][j] = min(dp[i-1][j]+incost,
			   min(dp[i][j-1]+rmcost,dp[i-1][j-1]+rcost));
	}
    }
    return dp[N][M];
}

int main(){
    char s[MAX],t[MAX];
    cin >> s >> t;
    cout << Levenshtein_Distance(s,t) << endl;
    return 0;
}
