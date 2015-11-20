#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_C = 60;
const int MAX_T = 150;
 
int c[MAX_C],t[MAX_T];
 
void init_c(){
    for(int i = 0 ; i < MAX_C ; i++){
	c[i] = i*i*i;
    }
}
 
void init_t(){
    for(int i = 2 ; i < MAX_T ; i++){
	t[i-2] = i*(i-1)*(i-2)/6;
    }
}
 
int main(){
    int n;
 
    init_c();
    init_t();
 
    while(cin >> n ,n){
	int ans = 0;
	for(int i = 0 ; i < MAX_C ; i++){
	    for(int j = 0 ; j < MAX_T-2 ; j++){
		if(c[i]+t[j] <= n){
		    ans = max(ans , c[i] + t[j]);
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
