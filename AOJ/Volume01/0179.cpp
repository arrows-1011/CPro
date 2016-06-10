#include <bits/stdc++.h>
 
using namespace std;
 
int len;
string str;
 
bool check(string s)
{
    char ch = s[0];
 
    for (int i = 1; i < len; i++) {
	if (ch != s[i]) return false;
    }
    return true;
}
 
int bfs()
{
    string ans;
    queue<string> Q;
    Q.push(str);
 
    bool found = false;
    set<string> used;
    used.insert(str);
    map<string,int> dist;
    dist[str] = 0;
 
    while (!Q.empty()) {
	string s = Q.front(); Q.pop();
     
	if (check(s)) {
	    found = true;
	    ans = s;
	    break;
	}
 
	for (int i = 1; i < len; i++) {
	    string next = s;
	    if (s[i-1] == 'b' && s[i] == 'r' ||
	       s[i-1] == 'r' && s[i] == 'b') {
		next[i-1] = next[i] = 'g';
	    } else if (s[i-1] == 'b' && s[i] == 'g' ||
		     s[i-1] == 'g' && s[i] == 'b') {
		next[i-1] = next[i] = 'r';
	    } else if(s[i-1] == 'r' && s[i] == 'g' ||
		     s[i-1] == 'g' && s[i] == 'r') {
		next[i-1] = next[i] = 'b';
	    }
       
	    if (!used.count(next)) {
		dist[next] = dist[s] + 1;
		used.insert(next);
		Q.push(next);
	    }
	}
    }
    if (!found) return -1;
    return dist[ans];
}
 
int main()
{
    while (cin >> str,str != "0") {
	len = (int)str.size();
	int res = bfs();
	if (res == -1) {
	    cout << "NA" << endl;
	} else {
	    cout << res << endl;
	}
    }
    return 0;
}
