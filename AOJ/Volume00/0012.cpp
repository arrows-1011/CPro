#include <iostream>
#include <cmath>
 
using namespace std;
 
#define D double
  
D heron(D a,D b,D c){
    D s = (a + b + c) / 2;
    D S = sqrt(s*(s - a)*(s - b)*(s - c));
    return S;
}
  
int main(){
    D x1,y1,x2,y2,x3,y3,xp,yp;
    
    while( cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp ){
	D a = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
	D b = sqrt(pow(x1-x3,2) + pow(y1-y3,2));
	D c = sqrt(pow(x3-x2,2) + pow(y3-y2,2));
	D S1 = heron(a,b,c);
      
	D x = sqrt(pow(x1-xp,2) + pow(y1-yp,2));
	D y = sqrt(pow(x2-xp,2) + pow(y2-yp,2));
	D z = sqrt(pow(x3-xp,2) + pow(y3-yp,2));
	D S2 = heron(x,y,a) + heron(x,z,b) + heron(y,z,c);
      
	if ((float)S1 == (float)S2){
	    cout << "YES" << endl;
	}else{
	    cout << "NO" << endl;
	}
    }
    return 0;
}
