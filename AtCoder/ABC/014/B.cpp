#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,X;
    cin >> n >> X;
    int res = 0;
    for(int i = 0 ; i < n ; i++){
	int a;
	cin >> a;
	if((X >> i) & 1){
	    res += a;
	}
    }
    cout << res << endl;
    return 0;
}
