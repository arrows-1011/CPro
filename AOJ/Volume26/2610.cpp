#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N;
    cin >> N;
    if(N == 0 || N == 2){
	cout << 1 << endl;
    }else if(N == 1){
	cout << 2 << endl;
    }else{
	cout << 0 << endl;
    }
    return 0;
}
