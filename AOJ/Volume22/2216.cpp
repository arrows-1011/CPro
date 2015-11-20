#include <iostream>

using namespace std;
 
int main(){
    int CD,Buyer;
    int cnt100,cnt500,cnt1000;
    int change;
 
    while(1){
	cnt100 = cnt500 = cnt1000 = 0;
	change = 0;
 
	cin >> CD >> Buyer;
	if( CD == 0 && Buyer == 0 ) break;
 
	change = Buyer - CD;
	while( change != 0 ){
	    if( change >= 1000 ){
		change -= 1000;
		cnt1000++;
	    }
	    else if( change >= 500 && change < 1000 ){
		change -= 500;
		cnt500++;
	    }
	    else if( change >= 100 && change < 500 ){
		change -= 100;
		cnt100++;
	    }
	}
	cout << cnt100 <<" "<< cnt500 <<" "<< cnt1000 << endl;
    }
    return 0;
}
