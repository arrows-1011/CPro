#include <bits/stdc++.h>
 
using namespace std;
 
#define PI M_PI
#define EPS 1e-9
 
int main(){
    double R;
    while(cin >> R, R > 0){
	double n = 0,d = 1;
	while(true){
	    if(fabs(PI-n/d) <= R+EPS){
		cout << (int)n << "/" << (int)d << endl;
		break;
	    }else{ R+n/d < PI ? n++ : d++; }
	}
    }
    return 0;
}
