#include <bits/stdc++.h>
 
using namespace std;
 
bool arr[1010];
 
int main(){
    int N,M,c,d;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
	cin >> c >> d;
	for(int j = c ; j < d ; j++){
	    arr[j] = true;
	}
    }
    cout << N+2*count(arr,arr+N,1)+1 << endl;
    return 0;
}
