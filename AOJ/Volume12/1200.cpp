#include <iostream>
using namespace std;
#define MAX 50000
 
bool prime[MAX];
 
void is_prime(){
    fill(prime,prime+MAX,true);
    prime[0] = prime[1] = false;
     
    for(int i = 2 ; i*i < MAX ; i++){
        if(prime[i]){
            for(int j = 2*i ; j < MAX ; j += i){
                prime[j] = false;
	    }
	}
    }
}
 
int main(){
    int n;
    is_prime();
    while(cin >> n,n){
        int cnt = 0;    
        for(int i = 2 ; i <= n/2 ; i++){
            if(prime[i]&&prime[n-i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
