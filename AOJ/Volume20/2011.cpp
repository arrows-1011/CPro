#include <bits/stdc++.h>
   
using namespace std;
   
#define MAX 50
   
int N, day;
bool ok[MAX][31];
bool visited[MAX];
   
void init(){
    day = 0;
    memset(ok, false, sizeof(ok));
}
   
int solve(){
    int ans = -1;
    set<int> dp[MAX];
  
    for(int i = 0 ; i < N ; i++){
	dp[i].insert(i);
    }
  
    for(int i = 0 ; i <= day ; i++){
	for(int j = 0 ; j < N-1 ; j++){
	    if(!ok[j][i]) continue;
	    for(int k = j+1 ; k < N ; k++){
		if(ok[k][i]){
		    set<int>::iterator it;
		    for(it = dp[j].begin() ; it != dp[j].end() ; ++it){
			dp[k].insert(*it);
		    }
		    for(it = dp[k].begin() ; it != dp[k].end() ; ++it){
			dp[j].insert(*it);
		    }
		}
	    }
	    if(dp[j].size() == N) return i+1;
	}
    }
    return ans;
}
   
int main(){
    int K, in;
    while(cin >> N && N){
	init();
	for(int i = 0 ; i < N ; i++){
	    cin >> K;
	    for(int j = 0 ; j < K ; j++){
		cin >> in;
		ok[i][in-1] = true;
		day = max(day, in);
	    }
	}
	cout << solve() << endl;
    }
    return 0;
}
