#include <bits/stdc++.h>

using namespace std;

#define MAX 55

string s;
string memo[MAX][MAX];

string get_max(string a, string b)
{
    int alen = a.size(), blen = b.size();
    if (alen > blen) {
        return a;
    } else if (alen < blen) {
        return b;
    }
    return (a > b ? a : b);
}

bool is_pare(int l, int r)
{
    int p = l + 1;
    if (r - l < 5) return 0;
    return ((s[p] == '?' || s[p] == '(') &&
            (s[r] == '?' || s[r] == ')'));
}

string dfs(int l, int r)
{
    string &res = memo[l][r];
    if (res != "*") return res;    
            
    if (s[l] == 'L' || s[l] == 'R' || s[l] == '?') {        
        if (is_pare(l, r)) {
            for (int i = l+3; i <= r-2; i++) {
                if (s[i] == ',' || s[i] == '?') {
                    if (s[l] == 'L' || s[l] == '?') {
                        if (dfs(i+1, r-1) != "/") {
                            res = get_max(res, dfs(l+2, i-1));      
                        }
                    }
                    if (s[l] == 'R' || s[l] == '?') {
                        if (dfs(l+2, i-1) != "/") {
                            res = get_max(res, dfs(i+1, r-1));                   
                        }
                    }
                }
            }
        }
    }
    string ss;
    for (int i = l; i <= r; i++) {
        if (isdigit(s[i])) {
            ss += s[i];
        } else if (s[i] == '?') {
            ss += "9";
        } else {
            ss = "/";
            break;
        }           
    }
    if (!ss.empty() && ss[0] == '0' && ss.size() > 1) {
        ss = "/";
    }
    res = get_max(res, ss);
    return res;
}

void init_table()
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            memo[i][j] = "*";
        }        
    }
}

int main()
{
    cin >> s;
    init_table();
    string res = dfs(0, s.size()-1);
    if (res == "/" || res == "*") {
        cout << "invalid" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
