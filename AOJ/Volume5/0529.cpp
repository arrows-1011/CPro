#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    int n,m;
 
    while(cin >> n >> m , n + m){
	vector<int> v;
	int a;
 
	for(int i = 0 ; i < n ; i++){
	    cin >> a;
	    v.push_back(a);
	}
 
	int size = v.size();
	for(int i = 0 ; i < size ; i++){
	    for(int j = 0 ; j < size ; j++){
		v.push_back(v[i]+v[j]);
	    }
	}
     
	sort(v.begin(),v.end());
 
	int ans = 0;
	for(int i = 0 ; i < v.size() ; i++){
	    int want = m - v[i];
	    int l = 0,r = v.size()-1;
 
	    if(want < 0) continue;
 
	    while(r - l > 1){
		int mid = (l+r) /2;
		if(v[mid] >= want){
		    r = mid;
		}
		else{
		    l = mid;
		}
		if(v[l] + v[i] <= m){
		    ans = max(ans,v[l]+v[i]);
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
