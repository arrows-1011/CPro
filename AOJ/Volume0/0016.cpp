#include <iostream>
#include <cmath>

using namespace std;

#define PI acos(-1)

double toRad(double ang){
    return (ang*PI/180);
}

int main(){
    char c;
    double a,b,x = 0,y = 0,rd = 0;
    while(cin >> a >> c >> b){
	if(a == 0 && b == 0) break;
	x += a*sin(toRad(rd));
	y += a*cos(toRad(rd));
	rd += b;
    }
    cout << (int)x << endl << (int)y << endl;
    
    return 0;
}
