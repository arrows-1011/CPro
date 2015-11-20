#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
 
using namespace std;
 
#define MAX 20
 
double L[MAX],a[MAX],b[MAX];
 
double calc(int x,int y){
    return pow(L[x]-L[y],2)+pow(a[x]-a[y],2)+pow(b[x]-b[y],2);
}
 
int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
	cin >> L[i] >> a[i] >> b[i];
    }
    double ans = 0;
    for(int S = 0 ; S < 1<<N ; S++){
	if(__builtin_popcount(S) == M){
	    double dist = 0;
	    vector<int> vec;
	    for(int i = 0 ; i < N ; i++){
		if(!(S >> i & 1)) continue;
		vec.push_back(i);
	    }
	    for(int i = 0 ; i < M ; i++){
		for(int j = i+1 ; j < M ; j++){
		    dist += calc(vec[i],vec[j]);
		}
	    }
	    ans = max(ans,dist);
	}
    }
    printf("%.10f\n",ans);
 
    return 0;
}
