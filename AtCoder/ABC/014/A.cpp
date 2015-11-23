#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a,b;
    cin >> a >> b;
    int c = a % b;
    if(c == 0){
	cout << 0 << endl;
    }else{
	cout << b - c << endl;
    }
    return 0;
}
