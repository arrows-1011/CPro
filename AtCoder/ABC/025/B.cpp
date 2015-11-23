#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,A,B,d;
    string s;
    cin >> N >> A >> B;
    int x = 0;
    for(int i = 0 ; i < N ; i++){
	cin >> s >> d;
	int nd = d;
	if(d < A) nd = A;
	else if(d > B) nd = B;
	if(s == "East"){
	    x += nd;
	}else{
	    x -= nd;
	}
    }
    if(x == 0){
	cout << 0 << endl;
    }else if(x > 0){
	cout << "East " << x << endl;
    }else{
	cout << "West " << -x << endl;
    }
    return 0;
}
