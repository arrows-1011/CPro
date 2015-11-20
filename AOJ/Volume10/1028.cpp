#include <bits/stdc++.h>
 
using namespace std;
 
int P,N[6];
const int coin[6] = {1,5,10,50,100,500};
 
int calc(int x){
    int res = 0;
    for(int i = 5 ; i >= 0 ; i--){
	if(x >= coin[i]){
	    res += x/coin[i];
	    x %= coin[i];
	}
    }
    return res;
}
 
int c(int x){
    int res = 0;
    for(int i = 5 ; i >= 0 ; i--){
	int use = x/coin[i];
	if(use > N[i]){
	    res += N[i];
	    x -= N[i]*coin[i];
	}else{
	    res += use;
	    x %= coin[i];
	}
    }
    return res;
}
 
int main(){
    while(cin >> P){
	int end = P;
	for(int i = 0 ; i < 6 ; i++){
	    cin >> N[i];
	    end += N[i];
	}
	if(end == 0) break;
	int res = (1<<29);
	for(int i = P ; i <= P+500 ; i++){
	    int x = c(i);
	    res = min(res,x+calc(i-P));
	}
	cout << res << endl;
    }
    return 0;
}
