#include <iostream>

using namespace std;
 
void res(int,int,int);
 
int main(void){
    int n,pm,pe,pj;
 
    for(;;){  
	cin >> n;
	if( n == 0 ) break;
 
	for( int i = 0 ; i < n ; i++ ){
	    cin >> pm >> pe >> pj;
	    res(pm,pe,pj);
	}
    }
    return 0;
}
 
void res(int pm,int pe,int pj){
    double ave,meave;
 
    ave = (double)(pm+pe+pj) / 3;
    meave = (double)(pm+pe) / 2;
 
    if( pm == 100 || pe == 100 || pj == 100 || meave >= 90 || ave >= 80 )
	cout << 'A' << endl;
    else if( ave >= 70 || ( ave >= 50 && ( pm >= 80 || pe >= 80 )))
	cout << 'B' << endl;
    else cout << 'C' << endl;
}
