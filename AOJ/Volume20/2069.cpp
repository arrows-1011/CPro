#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
#define MAX_N 50
#define MAX 50001
#define INF 1e9
int n, c[MAX_N];
 
int getNum(){
    int cost[MAX];
 
    memset(cost,0,sizeof(cost));
    cost[0] = 1;
    for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < MAX-c[i] ; j++){
	    cost[c[i]+j] += cost[j];
	}
    }
 
    for(int i = 0 ; i < MAX ; i++){
	if(cost[i] == 0){
	    return 1;
	}
    }
 
    fill(cost,cost+MAX,INF);
    cost[0] = 0;
    for(int i = 0 ; i < n ; i++){
	for(int j = c[i] ; j < MAX ; j++){
	    cost[j] = min(cost[j], cost[j-c[i]]+ 1);
	}
    }
 
    int s = MAX-1;
    for(int i = s ; i >= 1 ; i--){
	int rem = i, cnt = 0;
	for(int j = n-1 ; j >= 0 ; j--){
	    if(rem >= c[j]){
		cnt += rem / c[j];
		rem %= c[j];
	    }
	}
	if(cost[i] != cnt){
	    return 2;
	}
    }
 
    return 3;
}
 
int main(){
    int Tc = 1;
 
    while(scanf("%d" ,&n), n){
	for(int i = 0 ; i < n ; i++){
	    scanf("%d" , c+i);
	}
	int num = getNum();
	printf("Case #%d: " ,Tc++);
	if(num == 1){
	    puts("Cannot pay some amount");
	}else if(num == 2){
	    puts("Cannot use greedy algorithm");
	}else{
	    puts("OK");
	}
    }
    return 0;
}
