#include <iostream>
 
using namespace std;
 
typedef pair<int,string> P;
 
int main(){
    int n,q;
    P p[50];
 
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
	cin >> p[i].first >> p[i].second;
    }
 
    string ans = "kogakubu10gokan";
    int t = 0;
    for(int i = 0 ; i < n ; i++){
	if(q < p[i].first){
	    t++;
	    cout << ans << endl;
	    break;
	}
	ans = p[i].second;
    }
    if(!t) cout << ans << endl;
 
    return 0;
}
