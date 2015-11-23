#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,x,y;
    bool ok = true;
    bool visited[110] = {false};
    cin >> N >> x >> y;
    visited[x] = visited[y] = true;
    cin >> x;
    for(int i = 0 ; i < x ; i++){
	cin >> y;
	if(visited[y]){
	    ok = false;
	}
	visited[y] = true;
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
