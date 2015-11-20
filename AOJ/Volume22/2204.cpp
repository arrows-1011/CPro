#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int n;
 
    while(cin >> n ,n){
	int MAX_POINT = 0,MIN_POINT = 1<<28,sum,a[5];
	for(int i = 0 ; i < n ; i++){
	    sum = 0;
	    for(int j = 0 ; j < 5 ; j++){
		cin >> a[j];
		sum += a[j];
	    }
	    MAX_POINT = max(MAX_POINT,sum);
	    MIN_POINT = min(MIN_POINT,sum);
	}
	cout << MAX_POINT << ' ' << MIN_POINT << endl;
    }
    return 0;
}
