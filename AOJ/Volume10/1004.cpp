#include <iostream>

using namespace std;

#define MAX 10100
 
int prime[MAX];
 
void is_prime(){
    for(int i = 0 ; i < MAX ; i++) prime[i] = 0;
    prime[0] = prime[1] = 1;
 
    for(int i = 2 ; i*i < MAX ; i++)
	if(!prime[i])
	    for(int j = 2*i ; j < MAX ; j += i)
		prime[j] = 1;
}
 
int main(){
    int n;
 
    is_prime();
    while(cin >> n){
	int cnt = 0;
	for(int i = 1, j = n ; i <= n && j >= 1 ; i++,j--)
	    if(!prime[i]&&!prime[j]) cnt++;
 
	cout << cnt << endl;
    } 
    return 0;
}
