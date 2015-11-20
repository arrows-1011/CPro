#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    int N;
    cin >> N;
    while(N--){
	ll x[9];
	for(int i = 0 ; i < 9 ; i++){
	    scanf("%llx",&x[i]);
	}
	ll K = 0LL;
	for(int i = 0 ; i < 32 ; i++){
	    ll sum = 0LL;
	    for(int j = 0 ; j < 8 ; j++){
		sum += (x[j]^K);
	    }
	    if((sum & (1LL<<i)) != ((x[8]^K) & (1LL<<i))){
		K |= (1LL<<i);
	    }
	}
	printf("%llx\n",K);
    }
    return 0;
}
