#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e4;
 
bool p[MAX];
vector<int> prime;
int n,sum[MAX+1];
 
void is_prime(){
    fill(p,p+MAX,true);
    p[0] = p[1] = false;
 
    for(int i = 2 ; i*i <= MAX ; i++){
	if(p[i]){
	    for(int j = i*i ; j <= MAX ; j += i){
		p[j] = false;
	    }
	}
    }
}
 
void init(){
    is_prime();
    for(int i = 0 ; i < MAX ; i++){
	if(p[i]) prime.push_back(i);
    }
}
 
void solve(){
    int sum = 0 ,cnt = 0 ,t = 0;
    for(int i = 0 ; i < prime.size() ; i++){
	sum += prime[i];
	if(sum == n) cnt++;   
	while(sum >= n){
	    sum -= prime[t++];
	    if(sum == n) cnt++;   
	}
    }
    cout << cnt << endl;
}
 
int main(){
    init();
    while(cin >> n ,n){
	solve();
    }
    return 0;
}
