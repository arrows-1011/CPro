#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_G 10
#define MAX_K 2000
typedef long long ll;
 
int K,L[MAX_G];
ll value[MAX_G][MAX_K];
ll dp[MAX_G][MAX_K];
 
ll solve(int g,int k){
    if(k == K) return 0LL;
    if(g == MAX_G) return 0LL;
    ll &res = dp[g][k];
    if(res >= 0LL) return res;
    res = max(res,solve(g+1,k));
    for(int i = 0 ; i < L[g] ; i++){
	if(k+i+1 <= K){
	    res = max(res,solve(g+1,k+i+1)+value[g][i]);
	}else{
	    break;
	}
    }
    return res;
}
 
int main(){
    int N,C,G;
    vector<int> books[MAX_G];
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
	cin >> C >> G; G--;
	books[G].push_back(C);
    }
    for(int i = 0 ; i < MAX_G ; i++){
	sort(books[i].rbegin(),books[i].rend());
	L[i] = books[i].size();
	if(L[i] > 0) value[i][0] = books[i][0];
	for(int j = 1 ; j < L[i] ; j++){
	    books[i][j] += books[i][j-1];
	    value[i][j] = books[i][j]+j*(j+1);
	}
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(0,0) << endl;
    return 0;
}
