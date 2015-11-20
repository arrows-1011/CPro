#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 50
 
int main(){
    double r;
    int n;
    while(cin >> r >> n, r){
	int H[MAX] = {0},xl,xr,h;
	for(int i = 0 ; i < n ; i++){
	    cin >> xl >> xr >> h;
	    xl += 20; xr += 20;
	    for(int j = xl ; j < xr ; j++){
		H[j] = max(H[j],h);
	    }
	}
	double res = (1<<29);
	for(int i = 20-r ; i < 20+r ; i++){
	    double rr = i-20+(i<20);
	    res = min(res,r+H[i]-sqrt(r*r-rr*rr));
	}
	printf("%.8f\n",res);
    }
    return 0;
}
