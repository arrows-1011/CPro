#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 1000001
  
int ru[MAX],cu[MAX];
int rv[MAX],cv[MAX];
int a[MAX],b[MAX],c,d;
int e[MAX],f[MAX],g,h;
  
int main(){
    int N,u,v,m,in;
    cin >> N >> u >> v >> m;
    for(int i = 0 ; i < MAX ; i++){
	ru[i] = cu[i] = rv[i] = cv[i] = -1;
	a[i] = b[i] = N;
	e[i] = f[i] = N;
    }
    c = d = g = h = N;
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    cin >> in;
	    ru[in] = i;
	    cu[in] = j;
	}
    }
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    cin >> in;
	    rv[in] = i;
	    cv[in] = j;
	}
    }
   
    bool usagi = false,neko = false;
    int x;
    while(m--){
	cin >> x;
	if(N == 1){
	    if(ru[x] != -1){
		u--;
	    }
	    if(rv[x] != -1){
		v--;
	    }
	    if(u == 0) usagi = true;
	    if(v == 0) neko = true;
	    if(usagi || neko) break;
	    continue;
	}
	if(ru[x] != -1){
	    a[ru[x]]--;
	    b[cu[x]]--;
	    if(ru[x] == cu[x]){
		if( N/2 == ru[x] && (N & 1) ){
		    c--;
		    d--;
		}else{
		    c--;
		}
		if(c == 0){ c = -1; u--; }
		if(d == 0){ d = -1; u--; }
	    } else if(ru[x]+cu[x] == N-1){
		d--;
		if(d == 0){ d = -1; u--; }
	    }
	    if(a[ru[x]] == 0){ ru[x] = -1; u--; }
	    if(b[cu[x]] == 0){ cu[x] = -1; u--; }
	}
  
	if(rv[x] != -1){
	    e[rv[x]]--;
	    f[cv[x]]--;
	    if(rv[x] == cv[x]){
		if(N/2 == rv[x] && (N&1) ){
		    g--;
		    h--;
		}else{
		    g--;
		}
		if(g == 0){ g = -1; v--; }
		if(h == 0){ h = -1; v--; }
	    } else if(rv[x]+cv[x] == N-1){
		h--;
		if(h == 0){ h = -1; v--; }
	    }
	    if(e[rv[x]] == 0){ rv[x] = -1; v--; }
	    if(f[cv[x]] == 0){ cv[x] = -1; v--; }
	}
	if(u <= 0) usagi = true; 
	if(v <= 0) neko = true; 
	if(usagi || neko){
	    break;
	}
    }
    while( cin >> x ){}
    if((usagi && neko) || (!usagi && !neko)){
	cout << "DRAW" << endl;
    }else if(usagi){
	cout << "USAGI" << endl;
    }else{
	cout << "NEKO" << endl;
    }
    return 0;
}
