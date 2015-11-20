#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> P;
 
int main(){
    int n;
 
    while(cin >> n,n){
	vector<P> v;
	int OutW = 0,w,f,e;
	for(int i = 0 ; i < n ; i++){
	    cin >> w >> f >> e;
	    v.push_back(P(f,w));
	    v.push_back(P(e,-w));
	}
	sort(v.begin(),v.end());
	int flg = 0;
	for(int i = 0 ; i < v.size() ; i++){
	    OutW += v[i].second;
	    if(OutW > 150) flg = 1; 
	}
	if(flg) cout << "NG" << endl;
	else cout << "OK" << endl;
    }
 
    return 0;
}
