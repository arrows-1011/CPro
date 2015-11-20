#include <iostream>
#include <algorithm>

using namespace std;

#define s(a) a.size()
#define push(a,b) a.push_back(b)
 
int main(){
    string RED,GREEN,up;
 
    while(cin >> RED , RED != "-"){
	string ans = "";
	int R = 0,G = 0,U = 0;   
	int t = 0;   
 
	cin >> GREEN >> up;
	while(R < s(RED) || G < s(GREEN) || U < s(up)){
	    if(t%2==0){
		if(GREEN[G] != up[U]){
		    push(ans,GREEN[G]);
		    G++;
		}
		else{
		    G++;U++; t++;
		}
	    }
	    else{
		if(RED[R] != up[U]){
		    push(ans,RED[R]);
		    R++; t++;
		}
		else{
		    R++;U++;
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
