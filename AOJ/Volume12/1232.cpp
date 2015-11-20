#include <iostream>
#include <vector>
 
using namespace std;
 
#define MAX 500000
#define INF (1<<29)
 
vector<int> vec;
 
void make(){
    bool prime[MAX];
    fill(prime,prime+MAX,true);
    prime[0] = prime[1] = false;
    for(int i = 2 ; i < MAX ; i++){
	if(prime[i]){
	    vec.push_back(i);
	    for(int j = 2*i ; j < MAX ; j+=i){
		prime[j] = false;
	    }
	}
    }
}
 
 
int main(){
    int M,A,B;
  
    make();
    while(cin >> M >> A >> B, (M | A | B)){
	int a,b,max = 0;
	for(int i = 0 ; i < (int)vec.size() ; i++){
	    for(int j = 0 ; j <= i ; j++){
		if(vec[i]*vec[j] > M) break;
		if(A*vec[i] <= vec[j]*B){
		    if(vec[i]*vec[j] > max){
			max = vec[i]*vec[j];
			a = vec[j]; b = vec[i];
		    }
		}
	    }
	}
	cout << a << " " << b << endl;
    }
    return 0;
}
