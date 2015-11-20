#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int w,d;
 
    while(cin >> w >> d , w | d){
	int left[w],right[d];
	for(int i = 0 ; i < w ; i++){
	    cin >> left[i];
	}
	for(int i = 0 ; i < d ; i++){
	    cin >> right[i];
	}
 
	sort(left,left+w);
	sort(right,right+d);
 
	int ans = 0;
	bool useW[w],useD[d];
	fill(useW,useW+w,true);
	fill(useD,useD+d,true);
 
	for(int i = 0 ; i < w ; i++){
	    for(int j = 0 ; j < d ; j++){
		if(left[i] == right[j] && useW[i] && useD[j]){
		    ans += left[i];
		    useW[i] = false;
		    useD[j] = false;
		}
	    }
	} 
 
	for(int i = 0 ; i < w ; i++){
	    if(useW[i]){
		ans += left[i];
	    }
	}
 
	for(int i = 0 ; i < d ; i++){
	    if(useD[i]){
		ans += right[i];
	    }
	}
	cout << ans << endl;
    } 
    return 0;
}
