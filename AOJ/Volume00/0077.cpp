#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    string s;
 
    while (cin >> s) {
	for (int i = 0; i < (int)s.size(); i++) {
	    if (s[i] == '@') {
		cout << string(s[i+1]-'0', s[i+2]);
		i += 2;
	    } else {
		cout << s[i];
	    }
	}
	cout << endl;
    }
    return 0;
}
