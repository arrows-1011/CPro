#include <iostream>

using namespace std;

#define MAX 1500000
 
bool prime[MAX];
 
void make(){
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
    make();
    while(cin >> n,n){
        int a,i;    
        if(prime[n]) cout << '0' << endl;
        else{
            for(i = n ; prime[i] != true ; i++);
            a = i;
            for(i = n ; prime[i] != true ; i--);
            cout << a-i << endl;
        }
    }
    return 0;
}
