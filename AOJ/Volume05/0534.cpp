#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10000
int arr[MAX+2],N;
 
int solve(int p){
    int lp = p, rp = p+1;
 
    while(true){
	if(lp <= 0 || rp >= N+1) break;
	int color = arr[lp],l,r;
	for(l = lp ; arr[l] == color ; l--);
	for(r = rp ; arr[r] == color ; r++);
	if((r-rp)+(lp-l) < 4) break;
	lp = l, rp = r;
    }
    return N - rp + lp + 1;
}
 
int main(){
    while(cin >> N, N){
	memset(arr,0,sizeof(arr));
	for(int i = 1 ; i <= N ; i++){
	    cin >> arr[i]; 
	}
	int ans = MAX;
	for(int i = 1 ; i <= N ; i++){
	    int tmp = arr[i];
	    for(int j = 0 ; j < 3 ; j++){
		if(arr[i] == j+1) continue;
		arr[i] = j+1;
		ans = min(ans,solve(i));   
	    }
	    arr[i] = tmp;
	}
	cout << ans << endl;
    }
    return 0;
}
