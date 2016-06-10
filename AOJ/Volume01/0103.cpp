#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    string res;
    int n, cnt = 0, cntH = 0, point = 0;
 
    cin >> n;
    for (int i = 0; i < n;) {
	cin >> res;
     
	if (res == "OUT") {
	    cnt++;
	    if (cnt == 3) {
		i++;
		cnt = 0;
		cout << point << endl;
		point = 0;
		cntH = 0;
	    }
	} else if (res == "HIT") {
	    cntH++;
	    if (cntH == 4) {
		point++; cntH--;
	    }
	} else {
	    point += cntH+1;
	    cntH = 0;
	}
    }
    return 0;
}
