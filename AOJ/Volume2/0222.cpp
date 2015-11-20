#include <iostream>
using namespace std;
const int MAX = 10000001;
 
bool prime[MAX];
 
void pr(){
    prime[0] = prime[1] = true;
 
    for(int i = 2 ; i*i < MAX ; i++){
	if(!prime[i]){
	    for(int j = i*i ; j < MAX ; j+=i){
		prime[j] = true;
	    }    
	}
    }
}
 
int main(){
    int n;
 
    pr();
    while(cin >> n ,n){
	for(int i = n ; i >= 0 ; i--){
	    if(!prime[i]&&!prime[i-2]&&!prime[i-6]&&!prime[i-8]){
		cout << i << endl;
		break;
	    }
	}
    }
    return 0;
}
