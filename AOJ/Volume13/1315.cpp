#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1010
 
int main(){
    int N;
    while(cin >> N, N > 0){
	int M[MAX],D[MAX],h[MAX],m[MAX],e[MAX],p[MAX];
	int Point[MAX] = {0},t[MAX];
	char ch;
	for(int i = 0 ; i < N ; i++){
	    scanf("%d/%d %d:%d %c %d",
		  &M[i],&D[i],&h[i],&m[i],&ch,&p[i]);
	    e[i] = (ch == 'I');
	}
	memset(t,-1,sizeof(t));
	for(int i = 0 ; i < N ; i++){
	    int totalm = 60*h[i]+m[i];
	    if(e[i] == 1){
		t[p[i]] = totalm;
	    }else{
		if(p[i] == 0){
		    for(int j = 1 ; j < MAX ; j++){
			if(t[j] == -1) continue;
			Point[j] += totalm-max(t[j],t[0]);
		    }
		}else{
		    if(t[0] != -1){
			Point[p[i]] += totalm-max(t[p[i]],t[0]);
		    }
		}
		t[p[i]] = -1;
	    }
	}
	cout << *max_element(Point+1,Point+MAX) << endl;
    }
    return 0;
}
