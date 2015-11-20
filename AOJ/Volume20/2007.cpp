#include <iostream>

using namespace std;
 
const int coin[4] = {10,50,100,500};
int cost,ans,a[4];
int ans_coin[4];
 
int check(int total){
    int res = 0;
 
    for(int i = 3 ; i >= 0 ; i--){
	res += total / coin[i];
	total %= coin[i];
    }
 
    return res;
}
 
void judge(){
    int ans = 1<<28;
   
    for(int i = 0 ; i <= a[0] ; i++){
	for(int j = 0 ; j <= a[1] ; j++){
	    for(int k = 0 ; k <= a[2] ; k++){
		for(int l = 0 ; l <= a[3] ; l++){
 
		    int sum = coin[0]*i+coin[1]*j+coin[2]*k+coin[3]*l;
		    if(sum < cost) continue;
 
		    int want = sum - cost;
		    int tmp = check(want) - (i + j + k + l);
 
		    if(tmp < ans){
			ans_coin[0] = i; ans_coin[1] = j;
			ans_coin[2] = k; ans_coin[3] = l;
			ans = tmp;
		    }
		}
	    }
	}
    }
}
 
int main(){  
    bool flg = false;
    while(cin >> cost ,cost){
	if(flg) cout << endl;
	for(int i = 0 ; i < 4 ; i++) cin >> a[i];
	judge();
	for(int i = 0 ; i < 4 ; i++){
	    if(ans_coin[i]){
		cout << coin[i] << " " << ans_coin[i] << endl;
	    }
	}
	flg = true;
    }
    return 0;
}
