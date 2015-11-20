#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
 
int main(){
    int n;
 
    cin >> n;
    ll a[n];
    for(int i = 0 ; i < n ; i++){
	cin >> a[i];
    }
    sort(a,a+n);
 
    ll ans = 1;
    for(int i = 0 ; i < n ; i++){
	if(a[i] > ans) break;
	else ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
