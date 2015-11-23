#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,a,res = 0;
    cin >> n;
    int p[] = {0,0,1,0,1,2,3,0,1,0};
    for(int i = 0 ; i < n ; i++){
	cin >> a;
	res += p[a];
    }
    cout << res << endl;
    return 0;
}
