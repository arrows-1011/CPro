#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 20000
 
int main(){
    int array[MAX],n,sum,ans;
 
    while(cin >> n){
	for(int i = 0 ; i < n ; i++) cin >> array[i];
 
	sort(array,array+n);    
 
	sum = 0;
	ans = 0;
	for(int i = 0 ; i < n ; i++){
	    sum += array[i];
	    ans += sum; 
	}
	cout << ans << endl;
    }
    return 0;
}
