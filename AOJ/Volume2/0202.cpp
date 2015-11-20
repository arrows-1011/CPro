#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 31;
const int MAX_C = 1e6;
int n,x,cost[MAX];
bool dp[MAX_C+1],prime[MAX_C+1];
 
void is_prime(){
    fill(prime,prime+MAX_C,true);
    prime[0] = prime[1] = false;
 
    for(int i = 2 ; i*i <= MAX_C ; i++){
	if(prime[i]){
	    for(int j = i*i ; j <= MAX_C ; j+=i){
		prime[j] = false;
	    }
	}
    }
}
 
int main(){
    is_prime();
    while(cin >> n >> x ,n + x){
	fill(dp,dp+MAX_C,false); 
	fill(cost,cost+MAX,0);
	for(int i = 0 ; i < n ; i++){
	    cin >> cost[i];
	    dp[cost[i]] = true;
	}
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j <= x ; j++){
		if(dp[j] && j+cost[i] <= x){
		    dp[j+cost[i]] = true;
		}
	    }
	}
	int ans = 0;
	for(int i = x ; i >= 0 ; i--){
	    if(prime[i]&&dp[i]){
		ans = i;
		break;
	    }
	}
	if(ans) cout << ans << endl;
	else cout << "NA" << endl;
    }
    return 0;
}
