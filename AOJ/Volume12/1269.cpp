#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1121
#define MAX_K 15
typedef long long ll;
 
bool prime[MAX_N];
ll dp[MAX_N][MAX_K];
 
void Prime(){
    fill(prime,prime+MAX_N,true);
    prime[0] = prime[1] = false;
 
    for(int i = 2 ; i*i < MAX_N ; i++){
	if(prime[i]){
	    for(int j = i*i ; j < MAX_N ; j += i){
		prime[j] = false;
	    }
	}
    }
}
 
void init(){
    Prime();
    vector<int> P;
    for(int i = 0 ; i < MAX_N ; i++){
	if(prime[i]){
	    P.push_back(i);
	}
    }
 
    dp[0][0] = 1;
    for(int i = 0 ; i < (int)P.size() ; i++){
	for(int j = MAX_K-2 ; j >= 0 ; j--){
	    for(int k = 0 ; k < MAX_N-P[i] ; k++){
		dp[P[i]+k][j+1] += dp[k][j];
	    }
	}
    }
}
 
int main(){
    int n,k;
 
    init();
    while(cin >> n >> k, n | k){
	cout << dp[n][k] << endl;
    }
    return 0;
}
