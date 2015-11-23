#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,res = 0;
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
	res += i*10000;
    }
    res /= N;
    cout << res << endl;
    return 0;
}
