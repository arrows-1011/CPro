#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    set<pair<int,int>> st;
    int N,h,m;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> h >> m;
	st.insert(make_pair(h,m));
    }
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> h >> m;
	st.insert(make_pair(h,m));
    }
    bool blank = false;
    for(auto x : st){
	if(blank){ cout << " "; }
	blank = true;
	printf("%d:%02d",x.first,x.second);
    }
    cout << endl;
    return 0;
}
