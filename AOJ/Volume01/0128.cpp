#include <bits/stdc++.h>
 
using namespace std;
 
string str[10], in;
 
void init(){
    str[0] = "* = ****";
    str[1] = "* =* ***";
    str[2] = "* =** **";
    str[3] = "* =*** *";
    str[4] = "* =**** ";
    str[5] = " *= ****";
    str[6] = " *=* ***";
    str[7] = " *=** **";
    str[8] = " *=*** *";
    str[9] = " *=**** ";
}
 
void solve(string s, int count)
{
    if (count) cout << endl;
 
    int len = (int)s.size();
    string ans[5];  
 
    if (len == 5) {
	for (int i = 0; i < len; i++) {
	    ans[i] = str[s[i]-'0'];
        }
    } else {
	for (int i = 0; i < 5-len; i++) {
	    ans[i] = str[0];
	}
   
	int t = 0;
	for (int i = 5-len; i < 5; i++) {
	    ans[i] = str[s[t++]-'0'];
        }
    }
 
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 5; j++) {
	    cout << ans[j][i];
	}
	cout << endl;
    }
}
 
int main()
{
    init();
    int count = 0;
    while (cin >> in) {
	solve(in, count);
	count++;
    }
    return 0;
}
