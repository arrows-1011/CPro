#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int x,y,k,res = 0;
    cin >> x >> y >> k;
    if(k <= y){
	res = x + k;
    }else{
	res = x + y; k -= y;
	res -= k;
    }
    cout << res << endl;
    return 0;
}
