#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,A[1010];
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> A[i];
    }
    sort(A,A+N,greater<int>());
    int sum = 0;
    for(int i = 0 ; i < N ; i+=2){
	sum += A[i];
    }
    cout << sum << endl;
    return 0;
}
