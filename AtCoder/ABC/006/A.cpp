#include <bits/stdc++.h>
 
using namespace std;
 
bool check(int N){
    if(N % 3 == 0){
	return true;
    }
    while(N > 0){
	if(N%10 == 3){
	    return true;
	}
	N /= 10;
    }
    return false;
}
 
int main(){
    int N;
    cin >> N;
    cout << (check(N) ? "YES" : "NO") << endl;
    return 0;
}
