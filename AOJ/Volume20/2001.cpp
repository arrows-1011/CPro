#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Q;
typedef pair<int,Q> P;
 
int main(){
    int n,m,a;
 
    while(cin >> n >> m >> a , n | m | a){
	vector<P> v;
	int h,p,q;
	for(int i = 0 ; i < m ; i++){
	    cin >> h >> p >> q;
	    v.push_back(P(h,Q(p,q)));
	}
	sort(v.begin(),v.end(),greater<P>());
 
	for(int i = 0 ; i < (int)v.size() ; i++){
	    if(v[i].second.first == a) a = v[i].second.second;
	    else if(v[i].second.second == a) a = v[i].second.first;
	}
	cout << a << endl;
    }
 
    return 0;
}
