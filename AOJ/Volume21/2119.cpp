#include <iostream>
#include <cstring>
#include <vector>
 
using namespace std;

#define MAX 20

int main(){
    int N,M,T = 1;
 
    while(cin >> N >> M , N | M){
	int cnt = 0;
	vector<int> res(M+1,0);
	res[0] = N;
 
	while(true){
	    vector<int> tmp(M+1,0);
 
	    if(res[M]) break;  
	    cnt++;      
 
	    for(int i = 0 ; i < M ; i++){
		if(res[i] >= 2){
		    tmp[i+1] += res[i] / 2;
		    tmp[0] += res[i] / 2;
		    if(res[i] % 2) tmp[i]++;
		}
		else
		    tmp[i] += res[i];
	    }
 
	    res = tmp;
	}
	cout << "Case " << T++ << ": ";
	cout << cnt << endl;
    }
    return 0;
}
