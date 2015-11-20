#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
 
int c[10];
 
bool check(){
    int sum = 0, MOD = c[9];
    rep(i,3) sum = (sum + c[i]) % MOD; 
    if((c[3]+c[4]+c[5])%MOD != sum) return false;
    if((c[6]+c[7]+c[8])%MOD != sum) return false;
    if((c[0]+c[3]+c[6])%MOD != sum) return false;
    if((c[1]+c[4]+c[7])%MOD != sum) return false;
    if((c[2]+c[5]+c[8])%MOD != sum) return false;
    if((c[0]+c[4]+c[8])%MOD != sum) return false;
    if((c[2]+c[4]+c[6])%MOD != sum) return false;
    return true;
}
 
int rec(int p,int S){
    int res = 0;
    if(__builtin_popcount(S) == 10){
	return check();
    }
    if(!c[p]){
	rep(i,10){
	    if((S >> i) & 1) continue;
	    c[p] = i+1;
	    res += rec(p+1,S|(1<<i));
	    c[p] = 0;
	}
    }else{
	res += rec(p+1,S);
    }
    return res;
}
 
int main(){
    while(true){
	int S = 0;
	bool EXIT = false;
	rep(i,10){
	    cin >> c[i];
	    if(c[i] > 0){
		S |= 1<<(c[i]-1);
	    }else if(c[i] == -1){
		EXIT = true;
	    }
	}
	if(EXIT) break;
	cout << rec(0,S) << endl;
    }
    return 0;
}
