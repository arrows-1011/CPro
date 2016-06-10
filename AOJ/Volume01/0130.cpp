#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 26
 
bool data[MAX][MAX];
bool used[MAX];
vector<char> ans;
set<int> st;
 
bool cyc(int now, int cnt)
{
    if (cnt == 1) {
	return 1;
    }
    set<int>::iterator it;
    for (it = st.begin(); it != st.end(); ++it) {
	int next = (*it) - 'a';
	ans.push_back((char)(*it));
	if (data[now][next] && cyc(next, cnt-1)) {
	    return 1;
	}
	ans.pop_back();
    }
    return 0;
}
 
int main()
{
    int n;
    string str;
 
    cin >> n;
    while (n--) {
	memset(data, 0, sizeof(data));
	st.clear();
 
	cin >> str;
	string tmp;
	for (int i = 0; i < (int)str.size(); i++) {
	    if (str[i] == '-') continue;
	    tmp += str[i];
	}
	str = tmp;
	st.insert(str[0]);
	for (int i = 2; i < (int)str.size(); i += 2) {
	    if (str[i-1] == '<') {
		data[str[i]-'a'][str[i-2]-'a'] = 1;
	    } else {
		data[str[i-2]-'a'][str[i]-'a'] = 1;
	    }
	    if (!st.count(str[i])) {
		st.insert(str[i]);
	    }
	}
 
	int size = st.size();
	set<int>::iterator it;
	for (it = st.begin(); it != st.end(); ++it) {
	    ans.clear();
	    memset(used, 0, sizeof(used));
	    ans.push_back((char)(*it));
    
	    if (cyc((*it)-'a', size)) {
		break;
	    }
	}
	for (int i = 0; i < (int)ans.size(); i++) {
	    cout << ans[i];
	}
	cout << endl;
    }
    return 0;
}
