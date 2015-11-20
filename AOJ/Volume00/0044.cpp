#include <iostream>

using namespace std;

#define MAX 50100
 
int main(){
    bool prime[MAX] = {0};
 
    prime[0] = prime[1] = true;
    for(int i = 2 ; i*i <= MAX-1 ; i++){
	if(!prime[i]){
	    for(int j = i*2 ; j <= MAX - 1 ; j += i){
		prime[j] = true;
	    }
	}
    }
 
    int n;
    while(cin >> n){
	for(int i = n-1 ; ; i--){
	    if(!prime[i]){
		cout << i << ' ';
		break;
	    }
	}
	for(int i = n+1 ; ; i++){
	    if(!prime[i]){
		cout << i << endl;
		break;
	    }
	}
    }
    return 0;
}
