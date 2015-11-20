#include <iostream>
#include <string>

using namespace std;
 
int main(){
    int n,m;
    int dx[4] = { 0 , 1 , 0 , -1 };
    int dy[4] = { 1 , 0 , -1 , 0 };
    int angle;
    string order;
    int x,y;
    int Go;
 
    while(1){
	angle = 0; x = y = 1;
	cin >> n >> m;
	if( n == 0 && m == 0 ) break;
	
	while(1){
	    cin >> order;
	    if( order == "RIGHT" ){
		angle++;
		if( angle == 4 ) angle = 0;
		continue;
	    }
	    else if( order == "LEFT" ){
		angle--;
		if( angle == -1 ) angle = 3;
		continue;
	    }
	    else if( order == "STOP" ){
		cout << x << " " << y << endl;
		break;
	    }
	    cin >> Go;
	    if( order == "FORWARD" ){
		x += dx[angle]*Go;
		y += dy[angle]*Go;
		if( x < 1 ) x = 1;
		if( y < 1 ) y = 1;
		if( x > n ) x = n;
		if( y > m ) y = m;
	    }
	    else if( order == "BACKWARD" ){
		x -= dx[angle]*Go;
		y -= dy[angle]*Go;
		if( x < 1 ) x = 1;
		if( y < 1 ) y = 1;
		if( x > n ) x = n;
		if( y > m ) y = m;
 
	    }
	}
    }
    return 0;
}
