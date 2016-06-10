#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int p, q;
 
    while (cin >> p >> q) { 
	int Quo[100], Rem[100];    
	bool flg = false;
	int begin, end, t = 0;
 
	for (int i = 0; i < 100; i++, t++) {
	    p *= 10;
	    Quo[i] = p / q;
	    Rem[i] = p % q;
	    p %= q;
 
	    for (int j = 0; j < i; j++) {
		if (Quo[i] == Quo[j] && Rem[i] == Rem[j]) {
		    begin = j;
		    end = i;
		    goto end;
		}
	    }
       
	    if (!p) {
		flg = true;
		break;
	    }
	}
    end:
	if (flg) {
	    for (int i = 0; i <= t; i++) {
		cout << Quo[i];
	    }
	    cout << endl;
	} else {
	    for (int i = 0; i < t; i++) {
		cout << Quo[i];
	    }
	    cout << endl;
    
	    for (int i = 0; i < begin; i++) cout << " ";
	    for (int i = begin; i < end; i++) cout << "^"; 
	    cout << endl;
	}    
    }
    return 0;
}
