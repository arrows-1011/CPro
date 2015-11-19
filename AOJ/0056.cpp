#include <iostream>

using namespace std;

#define MAX 50100
  
int prime[MAX-4];
  
void make(){
    for(int i = 0 ; i < MAX ; i++) prime[i] = 0;
    prime[0] = prime[1] = 1;
    for(int i = 4 ; i < MAX ; i += 2) prime[i] = 1;
      
    for(int i = 3 ; i*i < MAX ; i++){
        if(prime[i]) continue;
        for(int j = i*2 ; j < MAX ; j+= i)
            prime[j] = 1;
    }
}
  
int main(){
    int n;
          
    make();  
    while(1){
	cin >> n;
	if(!n) break;
              
	int cnt = 0;
	for(int i = 2 ; i <= n/2 ; i++){
	    if(!prime[i]&&!prime[n-i]) cnt++;
	}
	cout << cnt << endl;
    }
    return 0;
}
