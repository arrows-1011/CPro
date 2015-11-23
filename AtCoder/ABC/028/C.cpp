#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a[5];
    for(int i = 0 ; i < 5 ; i++) cin >> a[i];
    vector<int> v;
    for(int i = 0 ; i < (1<<5) ; i++){
	if(__builtin_popcount(i) != 3) continue;
	int sum = 0;
	for(int j = 0 ; j < 5 ; j++){
	    if(i >> j & 1){
		sum += a[j];
	    }
	}
	v.push_back(sum);
    }
    sort(v.rbegin(),v.rend());
    cout << v[2] << endl;
    return 0;
}
