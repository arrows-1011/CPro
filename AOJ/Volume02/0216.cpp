#include <iostream>

using namespace std;
 
int main()
{
    int w;
  
    while (cin >> w, w != -1) {
	int ans = 3130;
	w -= 10;
 
	if (w >= 10) {
	    ans -= 10*125;
	    w -= 10;
	} else if (w > 0) {
	    ans -= w*125;
	    w = 0;
	} else {
	    cout << ans << endl;
	    continue;
	}
 
	if (w >= 10) {
	    ans -= 10*140;
	    w -= 10;
	} else if (w > 0) {
	    ans -= w*140;
	    w = 0;
	} else {
	    cout << ans << endl;
	    continue;
	}
     
	if (w > 0) {
	    ans -= w*160;
	} else {
	    cout << ans << endl;
	    continue;
	} 
	cout << ans << endl;
    }
    return 0;
}
