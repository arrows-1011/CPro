#include <bits/stdc++.h>
 
using namespace std;
 
int N, M, size;
int ans, a[10];
vector<int> ast;
 
int _2(int x){
    int s = x*2, t = 0;
 
    while(s > 0){
	t += s % 10;
	s /= 10;
    }
    return t;
}
 
void solve(int d, int sum){
    if(d == size){
	if(sum % 10 == 0){
	    ans++;
	}
	return;
    }
 
    int _ast = ast[d];
    for(int i = 0 ; i < M ; i++){
	if(_ast == 2){
	    int s = _2(a[i]);
	    solve(d+1,sum+s);
	}else{
	    solve(d+1,sum+a[i]);
	}
    }
}
 
int main(){
    char ch;
    int sum = 0; ans = 0;
 
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> ch;
	if((N-i)%2 == 0){
	    if(ch == '*'){
		ast.push_back(2);
	    }else{
		sum += _2(ch - '0');
	    }
	}else{
	    if(ch == '*'){
		ast.push_back(1);
	    }else{
		sum += (ch - '0');
	    }
	}
    }   
 
    cin >> M;
    for(int i = 0 ; i < M ; i++){
	cin >> a[i];
    }
    size = ast.size();
    solve(0, sum);
    cout << ans << endl;    
   
    return 0;
}
