#include <bits/stdc++.h>
 
using namespace std;
 
#define M 300001
 
int main(){
    int N,Q,q,in,c[M]={0};
    cin >> N >> Q;
    for(int i = 0 ; i < N ; i++){
	scanf("%d",&in);
	c[in] = in;
    }
    for(int i = 1 ; i < M ; i++){
	c[i] = max(c[i],c[i-1]);
    }
    while(Q--){
	cin >> q;
	int r = 0;
	for(int i = q-1 ; i < M ; i += q){
	    r = max(r,c[i]%q);
	}
	printf("%d\n",r);
    }
    return 0;
}
