#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
typedef pair<int,int> P;
 
int main(){
    int n;
 
    while(cin >> n,n){
	vector<P> v,b;
	for(int i = 0 ; i < n ; i++){
	    int m,s,sum = 0,num;
	    cin >> num;
	    for(int j = 0 ; j < 4 ; j++){
		cin >> m >> s;
		sum += m*60 + s;
	    }
	    v.push_back(P(-sum,num));
	    b.push_back(P(sum,num));
	}
	sort(v.begin(),v.end());
	sort(b.begin(),b.end());
	cout << b[0].second << endl;
	cout << b[1].second << endl;
	cout << v[1].second << endl;
    }
    return 0;
}
