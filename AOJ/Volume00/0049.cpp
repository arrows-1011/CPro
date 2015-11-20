#include <iostream>
#include <cstdio>
using namespace std;
 
int main(void){
    int cntA = 0,cntB = 0,cntAB = 0,cntO = 0,num;
    string blood;
    char c;
 
    while(cin >> num >> c >> blood){
	if(blood  == "A") cntA++;
	else if(blood == "B") cntB++;
	else if(blood == "AB") cntAB++;
	else cntO++;
    }
    cout << cntA << endl;
    cout << cntB << endl;
    cout << cntAB << endl;
    cout << cntO << endl;
    return 0;
}
