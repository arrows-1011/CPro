#include <bits/stdc++.h>
   
int main(){
    int n, m;
   
    while(scanf("%d%d" ,&n ,&m), (n | m)){
	int N = n+m, arr[N];
	for(int i = 0 ; i < N ; i++){
	    scanf("%d" ,arr+i);
	}
	std::sort(arr, arr+N);
   
	int max = arr[0];
	for(int i = 0 ; i < N ; i++){
	    max = std::max(max, arr[i] - arr[i-1]);
	}
	printf("%d\n" ,max);
    }  
    return 0;
}
