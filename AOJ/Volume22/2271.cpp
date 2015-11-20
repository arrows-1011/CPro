#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;
 
int main(){
    char KUPC[301];
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0,ans;
 
    cin >> KUPC;
    for( int i = 0 ; i < strlen(KUPC) ; i++ ){   
	if( KUPC[i] == 'K') cnt1++;
	else if(KUPC[i] == 'U') cnt2++;
	else if(KUPC[i] == 'P') cnt3++; 
	else if(KUPC[i] == 'C') cnt4++;
    }
    ans = min( cnt1 , min( cnt2 , min( cnt3 , cnt4 ) ) );
    cout << ans << endl;
    return 0;
}
