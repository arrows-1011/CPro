#include <iostream>

using namespace std;
 
int p,q,a,n,cnt;
 
void dfs(int depth,int sum_p,int sum_q,int nowq){
    if(p*sum_q == sum_p*q){
	cnt++;
	return;
    }
 
    if(depth == n) return;
 
    for(int i = nowq ; i*sum_q <= a ; i++){
	dfs(depth+1,i*sum_p+sum_q,i*sum_q,i);
    }
}
 
int main(){
    while(cin >> p >> q >> a >> n , p + q + a + n){
	cnt = 0; 
	dfs(0,0,1,1);
	cout << cnt << endl;
    }
    return 0;
}
