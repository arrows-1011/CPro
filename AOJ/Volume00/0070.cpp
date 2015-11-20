#include <iostream>
#include <cstring>
 
using namespace std;
 
#define LIMIT 330
 
int cnt[11][LIMIT+1];
bool used[11];
 
void make(int k,int N,int sum){
    if(sum > LIMIT) return;
 
    if(N == 0){
	cnt[k][sum]++;
	return;
    }
 
    for(int i = 0 ; i <= 9 ; i++){
	if(!used[i]){
	    used[i] = true;
	    make(k + 1 , N - 1 ,sum + (k+1)*i);
	    used[i] = false;
	}
    }
}
 
void init(){
    for(int i = 0 ; i <= 10 ; i++){
	memset(used,false,sizeof(used));
	make(0,i,0);    
    }
}
 
int main(){
    int n,s;
 
    init();
    while(cin >> n >> s){
	if(s <= LIMIT){
	    cout << cnt[n][s] << endl;
	}else{
	    cout << 0 << endl;
	}
    }
    return 0;
}
