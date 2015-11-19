#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <cstring>
 
using namespace std;

#define MAX 15
#define INF 1e9

double dp[1 << MAX][MAX];
double dist[MAX][MAX];
int N;
 
double rec(int S,int v){
    if(dp[S][v] >= 0) return dp[S][v];
    if(S == (1 << N)-1 && v == 0) return dp[S][v] = 0;
 
    double res = INF;
    for(int i = 0 ; i < N ; i++){
	if(!(S >> i & 1)){ 
	    res = min(res,rec(S | 1 << i, i) + dist[v][i]);
	}
    }
    return dp[S][v] = res;
}
 
int main(){
    string in;
   
    while(getline(cin,in)){
	vector<double> v;
	stringstream s(in);
	int num,box_length;
 
	s >> box_length;
 
	while(s >> num){
	    v.push_back(num);
	}
 
	N = (int)v.size();
	memset(dp,-1,sizeof(dp));
 
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(i == j) dist[i][j] = 0;
		else dist[i][j] = sqrt(pow(v[i]+v[j],2.0)-pow(v[i]-v[j],2.0));
	    }
	}      
 
	dist[N][N] = 0;
 
	for(int i = 0 ; i < N ; i++){
	    dist[i][N] = dist[N][i] = v[i];   
	}
	N++;
	if(rec(0,0) <= box_length) cout << "OK" << endl;
	else cout << "NA" << endl;
    }
    return 0;
}
