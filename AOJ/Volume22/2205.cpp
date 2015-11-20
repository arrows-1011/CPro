#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<string,int> P;
 
bool check(string a,string b){
    for(int i = 0 ; i < 8 ; i++){
	if(b[i] != '*' && a[i] != b[i]){
	    return false;
	}
    }
    return true;
}
 
int main(){
    int n,m;
 
    while(cin >> n >> m ,(n | m)){
	P a[n];  
	string b;
 
	for(int i = 0 ; i < n ; i++){
	    cin >> a[i].first >> a[i].second;
	}
 
	int ans = 0;
	for(int i = 0 ; i < m ; i++){
	    cin >> b;
	    for(int j = 0 ; j < n ; j++){
		if(check(b,a[j].first)){
		    ans += a[j].second;
		    break;
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
