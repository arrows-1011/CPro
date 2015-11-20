#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    int n,a,b;
 
    while(cin >> n ,n){
	vector<int> v[n];
	for(int i = 0 ; i < n ; i++){
	    cin >> a;
	    for(int j = 0 ; j < a ; j++){
		cin >> b;
		v[i].push_back(b);
	    }
	}
	int check[101] = {0};
	int cnt[101] = {0};
	int ans;
 
	cin >> a;
	for(int i = 0 ; i < a ; i++){
	    cin >> check[i];
	}
	int t = 0;
	while(true){
	    if(t == n) break;
       
	    for(int i = 0 ; i < a ; i++){
		vector<int>::iterator pos;
		pos = find(v[t].begin(),v[t].end(),check[i]);
		if(pos == v[t].end()){
		    break;
		}
		else{
		    cnt[t]++;
		}
	    }
	    t++; 
	}
 
	int cnt1 = 0;
	for(int i = 0 ; i < n ; i++){
	    if(cnt[i] == a){
		ans = i+1;
		cnt1++;
	    }
 
	}
	if(cnt1 == 1) cout << ans << endl;
	else cout << "-1" << endl;   
    }
    return 0;
}
