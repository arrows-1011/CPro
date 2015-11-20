#include <iostream>
using namespace std;
const int MAX = 1e6;
typedef long long ll;
 
bool prime[MAX+1];
ll dp[MAX+1];
 
void is_prime(){
    fill(prime,prime+MAX+1,true);
 
    prime[0] = prime[1] = false;
    for(int i = 2 ; i*i <= MAX ; i++){
	if(prime[i]){
	    for(int j = i*i ; j <= MAX ; j+=i){
		prime[j] = false;
	    }
	}
    }
 
}
 
int eulerPhi(int n){
    int res = n;
 
    for(int i = 2 ; i*i <= n ; i++){
	if(n % i == 0){
	    res -= res / i;
	    while(n % i == 0) n /= i;
	}
    }
 
    if(n > 1) res -= res / n;
 
    return res;
}
 
void init(){
    is_prime();
 
    dp[1] = 2; // 0/1 , 1/1
 
    for(int i = 2 ; i <= MAX ; i++){
	if(prime[i]){
	    dp[i] = dp[i-1] + (i-1);
	}
	else{
	    dp[i] = dp[i-1] + eulerPhi(i);
	}
    }
 
}
 
int main(){
    int T,in;
 
    init();
 
    cin >> T;
    while(T--){
	cin >> in;
	cout << dp[in] << endl;
    }
    return 0;
}
