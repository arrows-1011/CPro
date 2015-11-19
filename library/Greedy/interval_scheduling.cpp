#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

//入力
int N,S[MAX_N],T[MAX_N];

//仕事をソートするためのpair配列
pair<int,int> itv[MAX_N];

void solve(){
    //pairは辞書順で比較される
    //終了時間の早い順にしたいため、Tをfirst、Sをsecondに入れる
    for(int i = 0 ; i < N ; i++){
	itv[i].first = T[i];
	itv[i].second = S[i];
    }
    sort(itv,itv+N);
  
    //tは最後に選んだ仕事の終了時間
    int ans = 0,t = 0;
    for(int i = 0 ; i < N ; i++){
	if(t < itv[i].second){
	    ans++;
	    t = itv[i].first;
	}
    }
    printf("%d\n",ans);
}

