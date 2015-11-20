#include <iostream>

using namespace std;
 
int main(){
    int nn,c,a,n;
 
    cin >> nn;
    while(nn--){
	int cnt = 0;
	cin >> c >> a >> n;
	while(true){
	    if(c >= 1 && a >= 1 && n >= 1){
		c--; a--; n--;
		cnt++;
	    }
	    else if(c >= 2 && a >= 1){
		c -= 2;
		a--;
		cnt++;
	    }
	    else if(c >= 3){
		c -= 3;
		cnt++;
	    }
	    else{
		break;
	    }
	}
	cout << cnt << endl;
    }
    return 0;
}
