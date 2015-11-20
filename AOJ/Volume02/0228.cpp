#include <iostream>
#include <string>

using namespace std;
 
int main(){
    int n,nm[100];
     
    while(true){
        string first = "0000000";
         
        cin >> n;
        if(n == -1) break;
         
        for(int i = 0 ; i < n ; i++){
            cin >> nm[i];
             
            string str;
            switch(nm[i]){
	    case 0:
		str = "0111111";
		break;
	    case 1:
		str = "0000110";
		break;
	    case 2:
		str = "1011011";
		break;
	    case 3:
		str = "1001111";
		break;
	    case 4:
		str = "1100110";
		break;
	    case 5:
		str = "1101101";
		break;
	    case 6:
		str = "1111101";
		break;
	    case 7:
		str = "0100111";
		break;
	    case 8:
		str = "1111111";
		break;
	    case 9:
		str = "1101111";
		break;
            }
            string ans = "";
            for(int j = 0 ; j < 7 ; j++){
                if(first[j]!= str[j]) ans += '1';
                else ans += '0';
            }
            cout << ans << endl;
            first = str;
        }
    }
    return 0;
}
