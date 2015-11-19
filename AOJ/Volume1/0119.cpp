#include <iostream>
#include <cstring>
 
using namespace std;
 
#define MAX 20
 
int main(){
    int n, m, a, b;
    bool G[MAX][MAX];
 
    memset(G, false, sizeof(G));
    cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
	cin >> a >> b;
	G[b-1][a-1] = true;
    }
    int rem = m;
    bool used[MAX];
    memset(used, false, sizeof(used));
    while(true){
	if(rem == 0) break;
	for(int i = 0 ; i < m ; i++){
	    if(used[i]) continue;
	    bool ok = true;
	    for(int j = 0 ; j < m ; j++){
		if(i != j && G[i][j]){
		    ok = false;
		    break;
		}
	    }
	    if(ok){
		cout << i+1 << endl;
		used[i] = true;
		rem--;
		for(int j = 0 ; j < m ; j++){
		    G[j][i] = false;
		}
	    }
	}
    }
    return 0;
}
