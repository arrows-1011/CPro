#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef pair<int,string> P;
 
int main(){
    int N, M[31];
 
    while(cin >> N, N){
	string name[N];
	int cnt[31] = {0};
	int d[N][31];
 
	for(int i = 0 ; i < N ; i++){
	    cin >> name[i] >> M[i];
	    for(int j = 0 ; j < M[i] ; j++){
		cin >> d[i][j];
		cnt[d[i][j]]++;
	    }
	}
    
	vector<P> vec;
	for(int i = 0 ; i < N ; i++){
	    int sum = 0;
	    for(int j = 0 ; j < M[i] ; j++){
		sum += N-cnt[d[i][j]]+1;
	    }
	    vec.push_back(P(sum,name[i]));
	}
	sort(vec.begin(), vec.end());
	cout << vec[0].first << " " << vec[0].second << endl;
    }
    return 0;
}
