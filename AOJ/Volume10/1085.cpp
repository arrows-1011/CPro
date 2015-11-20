#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,S;
    while(cin >> n >> S, n){
        vector<int> r(n);
        for(int i = 0 ; i < n ; i++){
            cin >> r[i];
        }
        sort(r.begin(),r.end());
        int res = 0;
        for(int i = 0 ; i < n-1 ; i++){
	    res += n-(upper_bound(r.begin()+i+1,r.end(),S-r[i])-r.begin());
	}
	cout << res << endl;
    }
    return 0;
}
