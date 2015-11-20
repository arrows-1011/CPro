#include <iostream>
#include <cstring>

using namespace std;
 
int main(){
    int n, m;
 
    cin >> n >> m;
    int a[n],b[m],c[n];
 
    memset(c,0,sizeof(c));
 
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];
 
    for(int i = 0 ; i < m ; i++){
	for(int j = 0 ; j < n ; j++){
	    if(a[j] <= b[i]){
		c[j]++;
		break;
	    }
	}
    }
 
    int ans,maxi = 0;
    for(int i = 0 ; i < n ; i++){
	if(maxi < c[i]){
	    maxi = c[i];
	    ans = i + 1;
	}
    }
    cout << ans << endl;
    return 0;
}
