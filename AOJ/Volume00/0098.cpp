#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
 
int main()
{
    int N, a[100][100];
    int ans = -INF;
 
    scanf("%d" ,&N);
    for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	    scanf("%d", &a[i][j]);
	    ans = max(ans, a[i][j]);
	}
    }
    for (int i = 0; i < N; i++) {
	int b[100] = {0};
	for (int j = i; j < N; j++) {
	    int sum = 0;
	    for (int k = 0; k < N; k++) {
		b[k] += a[j][k];
		sum = max(sum + b[k], 0);
		if(sum > 0) ans = max(ans, sum);
	    }
	}
    }
    printf("%d\n" ,ans);
    return 0;
}
