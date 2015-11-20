#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,s,d;
    cin >> N;
    while(N--){
	cin >> s >> d;
	int res = 0;
	for(int i = 0 ; i < 31 ; i++){
	    if(s >> i & 1){
		s += 1<<i;
		res++;
	    }
	    if(d >> i & 1){
		d -= 1<<i;
		res++;
	    }
	    if(s == d) break;
	}
	cout << res << endl;
    }
    return 0;
}
