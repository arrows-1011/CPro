#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
 
bool prime[MAX];
 
void make(){
    fill(prime,prime+MAX,true);
   
    prime[0] = prime[1] = false;
    for(int i = 2 ; i*i < MAX ; i++){
	if(prime[i]){
	    for(int j = i*i ; j < MAX ; j += i){
		prime[j] = false;
	    }
	}
    }
}
 
int main(){
    int n,p;
 
    make();
    while(true){
	cin >> n >> p;
	if(n == -1 && p == -1) break;
 
	vector<int> v;
	for(int i = n+1 ; i < n+500 ; i++){
	    if(prime[i]) v.push_back(i);
	}
 
	vector<int> ans;
	for(int i = 0 ; i < (int)v.size() ; i++){
	    for(int j = i ; j < (int)v.size() ; j++){
		ans.push_back(v[i]+v[j]);
	    }
	}
	sort(ans.begin(),ans.end());
 
	cout << ans[p-1] << endl;
    }  
    return 0;
}
