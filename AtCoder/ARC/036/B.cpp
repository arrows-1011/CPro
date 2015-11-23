#include <bits/stdc++.h>
 
using namespace std;
 
int a[300010],b[300010];
int c[300010],d[300010];
int e[300010];
 
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> a[i];
	b[N-i-1] = a[i];
    }
    c[0] = 1;
    d[0] = 1;
    for(int i = 1 ; i < N ; i++){
	if(a[i-1] < a[i]){
	    c[i] = c[i-1]+1;
	}else{
	    c[i] = 1;
	}
    }
    for(int i = 1 ; i < N ; i++){
	if(b[i-1] < b[i]){
	    d[i] = d[i-1]+1;
	}else{
	    d[i] = 1;
	}
    }
    for(int i = 0 ; i < N ; i++){
	e[i] = c[i]+d[N-i-1];
	e[i]--;
    }
    int m = 0;
    int s,u;
    for(int i = 0 ; i < N ; i++){
	if(m < e[i]){
	    m = e[i];
	    s = i-c[i]+2;
	    u = i+d[N-i-1];
	}
    }
    cout << u-s+1 << endl;
    return 0;
}
