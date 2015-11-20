#include <iostream>

using namespace std;
 
int main(){
    int w;
  
    while(1){
	cin >> w;
	if(w == -1) break;
     
	int ans = 3130;
	w -= 10;
 
	if(10 <= w){
	    ans -= 10*125;
	    w -= 10;
	}
	else if(0 < w){
	    ans -= w*125;
	    w = 0;
	}
	else{
	    cout << ans << endl;
	    continue;
	}
 
	if(10 <= w){
	    ans -= 10*140;
	    w -= 10;
	}
	else if(0 < w){
	    ans -= w*140;
	    w = 0;
	}
	else{
	    cout << ans << endl;
	    continue;
	}
     
	if(0 < w){
	    ans -= w*160;
	}
	else{
	    cout << ans << endl;
	    continue;
	} 
	cout << ans << endl;
    }
    return 0;
}
