#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int Tc;
    int a[9],b[9];
    double acnt,bcnt;
 
    cin >> Tc;
    while(Tc--){
	for(int i = 0 ; i < 9 ; i++){
	    cin >> a[i];
	}
	sort(a,a+9);
	for(int i = 0 ; i < 9 ; i++){
	    cin >> b[i];
	}
	acnt = bcnt = 0;
 
	do{
	    int aa = 0, bb = 0;
	    for(int i = 0 ; i < 9 ; i++){
		if(a[i] > b[i]) aa += a[i] + b[i];
		else bb += a[i] + b[i];
	    }
	    if(aa > bb) acnt++;
	    else bcnt++;
	}while(next_permutation(a,a+9));
	printf("%.6f %.6f\n",acnt/(acnt+bcnt),bcnt/(acnt+bcnt));
    }
    return 0;
}
