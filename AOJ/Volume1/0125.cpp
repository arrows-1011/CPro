#include <iostream>
 
using namespace std;
 
int Fairfield(int y,int m,int d){
    if(m <= 2) y--,m += 12;
    return 365*y+y/4-y/100+y/400+153*(m+1)/5+d-428;
}
 
int main(){
    int y1,m1,d1,y2,m2,d2;
 
    while(true){
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
 
	if(y1 == -1 && m1 == -1 && d1 == -1 && 
	   y2 == -1 && m2 == -1 && d2 == -1) break;
 
	cout << Fairfield(y2,m2,d2) - Fairfield(y1,m1,d1) << endl;
    }
    return 0;
}
