#include <iostream>

using namespace std;

#define MAX 10100
 
int prime[MAX]={0};
void make(){
    prime[0] = prime[1] = 1;
     
    for(int i = 2 ; i*i < MAX ; i++){
        if(!prime[i]){
            for(int j = i*2 ; j < MAX ; j += i){
                prime[j] = 1;
	    }
	}
    }
}
 
int main(){
    int n;
     
    make();
    while(cin >> n,n){
        int a,b;
        for(int i = 0 ; i <= n ; i++){
            if(i >= 2 && !prime[i] && !prime[i-2]){
                a = i-2;
                b = i;
            }
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}
