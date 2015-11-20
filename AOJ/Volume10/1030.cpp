#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 500
typedef pair<int,int> P;
typedef pair<int,P> Q;
 
int main(){
    int N,H,a,b;
    string str;
 
    while(cin >> N >> H, (N | H)){
	set<Q> st;
	for(int i = 0 ; i < H ; i++){
	    cin >> str >> a >> b; a--, b--;
	    if(str == "xy"){
		for(int j = 0 ; j < N ; j++){
		    st.insert(Q(a,P(b,j)));
		}
	    }else if(str == "yz"){
		for(int j = 0 ; j < N ; j++){
		    st.insert(Q(j,P(a,b)));
		}
	    }else{
		for(int j = 0 ; j < N ; j++){
		    st.insert(Q(a,P(j,b)));
		}
	    }
	}
	cout << N*N*N-st.size() << endl;
    }
    return 0;
}
