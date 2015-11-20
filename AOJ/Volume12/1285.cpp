#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,w,v;
    while(cin >> n >> w, n){
	int N = 0;
	double p[11] = {0},d = 0,ans = 0;
	for(int i = 0 ; i < n ; i++){
	    cin >> v; p[v/w]++;
	    N = max(N,v/w);
	    d = max(d,p[v/w]);
	}
	for(int i = 0 ; i < N ; i++){
	    ans += (p[i]/d)*((double)(N-i)/N);
	}
	printf("%f\n",ans+0.01);
    }
    return 0;
}
