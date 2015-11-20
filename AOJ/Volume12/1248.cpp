#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 55000
#define INF 1e9
typedef long long Int;
 
int main(){
    Int a,b,d;
    while(cin >> a >> b >> d, a){
	Int x,y;
	Int ansx,ansy,min1,min2;
	ansx = ansy = min1 = min2 = INF;
	for(x = 0 ; x < MAX ; x++){
	    Int ax = a*x;
	    y = (ax+d) % b;
	    if(ax+d >= b && y == 0){
		y = (ax+d)/b;
		if(x+y < min1){
		    min1 = x+y;
		    ansx = x;
		    ansy = y;
		}else if(x+y == min1 && ax+b*x < min2){
		    min2 = ax+b*x;
		    ansx = x;
		    ansy = y;
		}
	    }
	}
	for(y = 0 ; y < MAX ; y++){
	    Int by = b*y;
	    x = (by+d) % a;
	    if(by+d >= a && x == 0){
		x = (by+d)/a;
		if(x+y < min1){
		    min1 = x+y;
		    ansx = x;
		    ansy = y;
		}else if(x+y == min1 && a*x+by < min2){
		    min2 = a*x+by;
		    ansx = x;
		    ansy = y;
		}
	    }
	}
	for(y = 0 ; y < MAX ; y++){
	    Int by = b*y;
	    x = (d-by) % a;
	    if(d-by >= a && x == 0){
		x = (d-by)/a;
		if(x+y < min1){
		    min1 = x+y;
		    ansx = x;
		    ansy = y;
		}else if(x+y == min1 && a*x+by < min2){
		    min2 = a*x+by;
		    ansx = x;
		    ansy = y;
		}
	    }
	}
	cout << ansx << " " << ansy << endl;
    }
    return 0;
}
