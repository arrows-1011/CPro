#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 301
  
int dp[MAX][MAX];
int arr[MAX][MAX];
  
void init(int N,int M){
    for(int i = 0 ; i <= N ; i++){
	for(int j = 0 ; j <= M ; j++){
	    dp[i][j] = 0;
	    arr[i][j] = MAX;
	}
    }
}
 
string getStr(string &L,string &R,int l,int r){
    for(int i = 0 ; i < l ; i++){
	for(int j = 0 ; j < r ; j++){
	    if(L[i] == R[j]){
		dp[i+1][j+1] = dp[i][j]+1;
		arr[i+1][j+1] = 0;
	    }else{
		if(dp[i][j+1] < dp[i+1][j]){
		    dp[i+1][j+1] = dp[i+1][j];
		    arr[i+1][j+1] = -1;
		}else{
		    dp[i+1][j+1] = dp[i][j+1];
		    arr[i+1][j+1] = 1;
		}
	    }
	}
    }
    string res;
    for(int i = l, j = r ; i > 0 && j > 0 ; ){
	if(!arr[i][j]){
	    res += L[i-1];
	    i--; j--;
	}else if(arr[i][j] == 1){
	    i--;
	}else{
	    j--;
	}
    }
    reverse(res.begin(),res.end());
    return res;
}
 
int main(){
    string str;
    while(cin >> str, str != "#END"){
	int len = str.size(),res = 0;
	string res_str;
	for(int i = 1 ; i < len ; i++){
	    string L = str.substr(0,i);
	    string R = str.substr(i);
	    int l = L.size(),r = R.size();
	    init(l,r);
	    string repS = getStr(L,R,l,r);
	    l = repS.size();
	    if(res < l){
		res = l;
		res_str = repS;
	    }
	}
	cout << res_str << endl;
    }
    return 0;
}
