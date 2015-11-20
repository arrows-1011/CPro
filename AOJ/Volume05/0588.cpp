#include <iostream>

using namespace std;
 
int main(){
    char c;
    int b,ans;
     
    cin >> ans;
    while(1){
        cin >> c;
         
        if(c == '=') break;
        cin >> b;
        switch(c){
	case '+':
	    ans += b;
	    break;
                 
	case '-':
	    ans -= b;
	    break;
                 
	case '*':
	    ans *= b;
	    break;
                 
	case '/':
	    ans /= b;
	    break;
        }
    }
    cout << ans << endl;
    return 0;
}
