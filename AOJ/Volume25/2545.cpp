#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
#define MAX_N 7
#define MAX_M 11
 
struct P{
    int l, r, s;
};
 
int N, X, M;
P p[MAX_M];
 
bool check(int lion[]){
    for(int i = 0 ; i < M ; i++){
	int sum = 0;
	for(int j = p[i].l-1 ; j < p[i].r ; j++){
	    sum += lion[j];
	}
	if(sum != p[i].s) return false;
    }
    return true;
}
 
void print(int lion[]){
    for(int i = 0 ; i < N ; i++){
	printf("%d%c",lion[i], i != N-1 ? ' ' : '\n');
    }
}
 
bool rec(int pos, int lion[]){
    if(pos == N){
	if(check(lion)){
	    return true;
	}else{
	    return false;
	}
    }
 
    for(int i = X ; i >= 0 ; i--){
	lion[pos] = i;
	if(rec(pos+1, lion)){
	    return true;
	}
    }
    return false;
}
 
void solve(){
    int lion[MAX_N];
    memset(lion, 0, sizeof(lion));
 
    if(rec(0, lion)){
	print(lion);
    }else{
	printf("-1\n");
    }
}
 
int main(){
    scanf("%d%d%d" ,&N ,&X, &M);
    for(int i = 0 ; i < M ; i++){
	scanf("%d%d%d" ,&p[i].l , &p[i].r, &p[i].s);
    }
    solve();
 
    return 0;
}
