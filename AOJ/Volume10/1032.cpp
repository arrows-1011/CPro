#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define MAX 20
#define INF 1e9
 
vector<int> vec,v[MAX],a[MAX];
 
void init(int N){
    vec.clear();
    for(int i = 0 ; i < MAX ; i++){
	v[i].clear();
    }
    for(int i = 1 ; i < 1<<N ; i++){
	int idx = __builtin_popcount(i);
	v[idx-1].push_back(i);
    }
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < (int)v[i].size() ; j++){
	    vec.push_back(v[i][j]);
	}
    }
}
 
int main(){
    int N,U,c[MAX],k,r;
    bool used[MAX] = {false};
 
    while(cin >> N >> U, (N | U)){
	if(!used[N-1]){
	    init(N);
	    a[N-1] = vec;
	    used[N-1] = true;
	}else{
	    vec = a[N-1];
	}
	int arr[MAX];
	for(int i = 0 ; i < N ; i++){
	    cin >> c[i] >> k;
	    int S = 0;
	    for(int j = 0 ; j < k ; j++){
		cin >> r;
		S |= 1<<r;
	    }
	    arr[i] = S;
	}
	int ans = INF;
	for(int i = 0 ; i < (int)vec.size() ; i++){
	    int S = vec[i];
	    int cnt = 0, total = 0;
	    bool flg = true;
	    for(int j = 0 ; j < N ; j++){
		if(S >> j & 1){
		    if((S & arr[j]) == arr[j]){
			cnt += c[j]; total++;
		    }else{
			flg = false;
			break;
		    }
		}
	    }
	    if(flg && cnt >= U){
		ans = total;
		break;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
