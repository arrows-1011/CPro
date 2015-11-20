#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N;
    while(cin >> N){
	int x = 0,r = 1;
	for(int i = 0,j = 0 ; i < N ; i++,j++){
	    if(j == 2){ r *= 3; j = 0; }
	    x += r;
	}
	cout << x << endl;
    }
    return 0;
}
