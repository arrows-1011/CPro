#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
 
int main(){
    int a1,m1,a2,m2,a3,m3;
 
    while(true){
	cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3;
	if(a1+m1+a2+m2+a3+m3 == 0) break;
 
	ll xx = 0,yy = 0,zz = 0;
	ll x = 1,y = 1,z = 1;
	while(true){
	    x = a1*x%m1;
	    xx++;
	    if(x == 1) break;
	}
	while(true){
	    y = a2*y%m2;
	    yy++;
	    if(y == 1) break;
	}
	while(true){
	    z = a3*z%m3;
	    zz++;
	    if(z == 1) break;
	}
	cout << lcm(xx,lcm(yy,zz)) << endl;
    }
    return 0;
}
