#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n;
 
    while(cin >> n ,n){
	vector<int> v(n);
 
	for(int i = 0 ; i < n ; i++)
	    cin >> v[i];
 
	int cnt = 0;
	while(true){
	    vector<int> next(n);
	    for(int i = 0 ; i < n ; i++){
		next[i] = count(v.begin(),v.end(),v[i]);
	    }
 
	    if(v == next) break;
	    cnt++;
	    v = next;
	}
	cout << cnt << endl;
	for(int i = 0 ; i < n ; i++){
	    if(i) cout << " " << v[i];
	    else cout << v[i];
	}
	cout << endl;
    }
    return 0;
}
