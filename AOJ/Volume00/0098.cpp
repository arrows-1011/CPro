#include <cstdio>
#include <algorithm>
 
using namespace std;
 
#define INF 1e9
#define FOR(i,a,b) for(int i = a ; i < b ; i++)
 
int main(){
    int N,a[100][100];
    int ans = -INF;
 
    scanf("%d" ,&N);
    FOR(i,0,N){
	FOR(j,0,N){
	    scanf("%d" ,&a[i][j]);
	    ans = max(ans,a[i][j]);
	}
    }
    FOR(i,0,N){
	int b[100] = {0};
	FOR(j,i,N){
	    int sum = 0;
	    FOR(k,0,N){
		b[k] += a[j][k];
		sum = max(sum + b[k] ,0);
		if(sum) ans = max(ans,sum);
	    }
	}
    }
    printf("%d\n" ,ans);
    return 0;
}
