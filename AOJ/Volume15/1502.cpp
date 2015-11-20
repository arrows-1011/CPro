#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAX 500
typedef long long ll;
 
int main(){
    int n, arr[MAX];
 
    cin >> n;
    for(int i = 0 ; i < n ; i++){
	cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
	if(arr[i]-i/4 > 0){
	    ans += arr[i]-i/4;
	}
    }
    cout << ++ans << endl;
 
    return 0;
}
