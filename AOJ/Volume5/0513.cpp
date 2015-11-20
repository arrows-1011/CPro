#include <iostream>
#include <vector>

using namespace std;
 
int main(){
    int n,m;
    vector<int> v;
 
    cin >> n >> m;
    for(int i = 0 ; i < 2*n ; i++){
	v.push_back(i+1);
    } 
 
    int k;
    while(m--){
	cin >> k;
 
	if(k == 0){
	    vector<int> tmp;
	    int t = n;
	    for(int i = 0 ; i < n ; i++){
		tmp.push_back(v[i]);
		tmp.push_back(v[i+t]);
	    }
	    v = tmp;
	}
	else{
	    vector<int> tmp;
	    for(int i = 0 ; i < k ; i++){
		tmp.push_back(v[0]);
		v.erase(v.begin());
	    }
	    for(int i = 0 ; i < (int)tmp.size() ; i++){
		v.push_back(tmp[i]);
	    }
	}
    }
 
    for(int i = 0 ; i < (int)v.size() ; i++){
	cout << v[i] << endl;
    }
    return 0;
}
