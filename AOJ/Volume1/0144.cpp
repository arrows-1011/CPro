#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAX 100
#define INF 100000
 
int main(){
    int n;
    cin >> n;
    int d[MAX][MAX];
    for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < n ; j++){
	    d[i][j] = INF;
	}
    }
    for(int i = 0 ; i < n ; i++){
	int r,k,t;
	cin >> r >> k; r--;
	for(int j = 0 ; j < k ; j++){
	    cin >> t; t--;
	    d[r][t] = 1;
	}
    }
    for(int k = 0 ; k < n ; k++){
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
		d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
	    }
	}
    }
    int p,s,t,v;
    cin >> p;
    for(int i = 0 ; i < p ; i++){
	cin >> s >> t >> v; s--; t--;
	if(d[s][t]+1 <= v){
	    cout << d[s][t]+1 << endl;
	}else{
	    cout << "NA" << endl;
	}
    }
    return 0;
}
