#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char x)
{
    return (x == 'a' || x == 'i' || x == 'u' ||
            x == 'e' || x == 'o');
}

string change(string &s)
{
    string res;
    res += s[0];
    for (int i = 1; i < (int)s.size(); i++) {
        if (is_vowel(s[i-1])) {
            res += s[i];
        }
    }    
    return res;
}

bool check(vector<string> &t, int k, int N)
{
    set<string> st;
    for (int i = 0; i < (int)t.size(); i++) {
        if ((int)t[i].size() < k) {
            st.insert(t[i]);
        } else {
            st.insert(t[i].substr(0, k));
        }
    }
    return ((int)st.size() == N);
}

int main()
{
    int N;
    while (cin >> N, N) {
        string s;
        vector<string> t(N);
        for (int i = 0; i < N; i++) {
            cin >> s;
            t[i] = change(s);
        }
        
        int res = -1;
        for (int k = 1; k <= 50; k++) {
            if (check(t, k, N)) {
                res = k;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
