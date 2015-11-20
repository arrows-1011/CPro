#include <iostream>
#include <vector>

using namespace std;

const int MAX = 51;
 
int main(){
    int n,k,m,a,p,x,y;
    vector<bool> v(MAX);
    bool bu[MAX][MAX];
 
    fill(bu[0],bu[MAX],false);
 
    cin >> n >> k;
    for(int i = 0 ; i < k ; i++){
	cin >> m;
	for(int j = 0 ; j < m ; j++){
	    cin >> a;
	    bu[i][a] = true;
	}
    }
 
    cin >> p;
    for(int i = 0 ; i < p ; i++){
	cin >> x >> y;
	for(int j = 0 ; j < k ; j++){
	    if(bu[j][x] && bu[j][y]){
		v[x] = v[y] = true;
	    }
	}
    }
 
    int cnt = 0;
    for(int i = 0 ; i < MAX ; i++){
	if(v[i]) cnt++;
    }
 
    cout << cnt << endl;
    return 0;
}
