#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAX 2001
 
int dp[MAX][MAX];
int arr[MAX][MAX];
 
void init(int N){
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    dp[i][j] = 0;
	    arr[i][j] = MAX;
	}
    }
}
 
int main(){
    string s;
 
    while(cin >> s){
	string t = s;
	reverse(t.begin(), t.end());
  
	int len = s.size();  init(len+1);
	for(int i = 0 ; i < len ; i++){
	    for(int j = 0 ; j < len ; j++){
		if(s[i] == t[j]){
		    dp[i+1][j+1] = dp[i][j] + 1;
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
	string str;
	for(int i = len, j = len ; i > 0 && j > 0 ;){
	    if(!arr[i][j]){
		str += s[i-1];
		i--, j--;
	    }else if(arr[i][j] == 1){
		i--;
	    }else{
		j--;
	    }
	}
	cout << str << endl;
    }
 
    return 0;
}
