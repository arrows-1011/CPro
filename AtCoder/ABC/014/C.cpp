#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000010
 
int main(){
    int n,a,b;
    int arr[MAX] = {0};
    cin >> n;
    for(int i = 0 ; i < n ; i++){
	cin >> a >> b;
	arr[a]++; arr[b+1]--;
    }
    int sum = 0,res = 0;
    for(int i = 0 ; i < MAX ; i++){
	sum += arr[i];
	res = max(res,sum);
    }
    cout << res << endl;
    return 0;
}
