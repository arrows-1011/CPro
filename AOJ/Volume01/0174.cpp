#include <iostream>
#include <string>

using namespace std;
 
int main()
{
    string str;
   
    for (;;) {
	int cntA = 0, cntB = 0;
   
	cin >> str;
	if (str == "0") break;
     
	for (int i = 1; i < (int)str.size(); i++) {
	    if (str[i] == 'A') cntA++;
	    else cntB++;    
	}
     
	if (cntA > cntB) cntA++;
	else cntB++;
     
	cout << cntA << ' ' << cntB << endl;
    }
    return 0;
}
