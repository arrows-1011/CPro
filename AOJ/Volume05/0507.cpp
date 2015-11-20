#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<int> vec;
 
void rec(int N, int M){
    if(N == 0){
	int size = vec.size();
	for(int i = 0 ; i < size ; i++){
	    cout << vec[i] << (i != size-1 ? ' ' : '\n');
	}
    }else{
	for(int i = 0 ; i < M ; i++){
	    if(N - M + i >= 0){
		vec.push_back(M-i);
		rec(N - M + i, M - i);
		vec.pop_back();
	    }
	}
    }
}
 
int main(){
    while(cin >> n, n){
	rec(n, n);
    }
    return 0;
}
