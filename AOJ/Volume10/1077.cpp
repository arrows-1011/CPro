#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int Math,Greedy,Geometry,DP,Graph,Other;
 
    while(cin >> Math >> Greedy >> Geometry >> 
	  DP >> Graph >> Other){
 
	if(!Math && !Greedy && !Geometry && !DP &&
	   !Graph && !Other) break;
 
	int MD = Math + DP , GG = Greedy + Graph;
	int GO = Geometry + Other;
 
	int ans = 0;
	if(MD >= 0 && GG >= 0 && GO >= 0){
	    ans = max(ans, MD/3 + GG/3 + GO/3);
	}
	if(MD >= 1 && GG >= 1 && GO >= 1){
	    ans = max(ans, ((MD-1)/3 + (GG-1)/3 + (GO-1)/3) + 1);
	}
	if(MD >= 2 && GG >= 2 && GO >= 2){
	    ans = max(ans, ((MD-2)/3 + (GG-2)/3 + (GO-2)/3) + 2);
	}
	cout << ans << endl;
    }
    return 0;
}
