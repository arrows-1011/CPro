#include <iostream>

using namespace std;

const int MAX = 2000002;
bool c[MAX+1];
 
int main(){
    int n,a,b;
 
    while(cin >> n >> a >> b , n+a+b){
	int cnt = 0;
	for(int i = 0 ; i <= n ; i++) c[i] = false;
	c[0] = true;
     
	for(int i = 0 ; i <= n ; i++){
	    if(c[i]&&(i+a <= n||i+b <= n)){
		c[i+a] = true; c[i+b] = true;
	    }
	}
	for(int i = 1 ; i  <= n ; i++) 
	    if(!c[i]) cnt++;
 
	cout << cnt << endl;
    }
    return 0;
}
