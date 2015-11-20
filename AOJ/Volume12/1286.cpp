#include <bits/stdc++.h>
 
using namespace std;
 
int N,M,K;
map<int,int> mp;
 
void make(int n,int sum){
    if(N == n){
	if(sum-K <= 0){
	    mp[1]++;
	}else{
	    mp[sum-K]++;
	}
	return;
    }
    for(int i = 0 ; i < M ; i++){
	make(n+1,sum+i+1);
    }
}
 
int main(){
    while(cin >> N >> M >> K, N){
	mp.clear();
	make(0,0);
	double ans = 0;
	map<int,int>::iterator it;
	for(it = mp.begin() ; it != mp.end() ; ++it){
	    ans += ((double)it->second/pow((double)M,N))*it->first;
	}
	printf("%.8f\n",ans);
    }
    return 0;
}
