#include <cstdio>
#include <algorithm>
 
using namespace std;
 
struct lunch{
    int w,s;
    char name[21];
 
    bool operator < (const lunch &l)const{
	if(w != l.w){
	    return w < l.w;
	}else{
	    return s < l.s;
	}
    }
};
 
lunch N[10],ans[10];
int n;
 
void make(){
    for(int i = 0 ; i < n ; i++){
	ans[i] = N[i];
    }
}
 
bool check(int &G){
    int Ws1 = 0,Ws2 = 0;
    for(int i = 0 ; i < n ; i++){
	if(N[i].s < Ws2) return false;
	Ws1 += (i+1)*N[i].w;
	Ws2 += N[i].w;
    }
    G = Ws1;
 
    return true;
}
 
int main(){
    while(scanf("%d" ,&n) ,n){
	for(int i = 0 ; i < n ; i++){
	    scanf("%s %d %d" ,N[i].name ,&N[i].w ,&N[i].s);
	}
	sort(N,N+n);
 
	int G = 0,t;
 
	do{
	    if(check(t)){
		if(G < t){
		    make();
		    G = t;
		}
	    }
	}while(next_permutation(N,N+n));
 
	for(int i = n-1 ; i >= 0 ; i--){
	    printf("%s\n" ,ans[i].name);
	}
    }
    return 0;
}
