#include <bits/stdc++.h>

using namespace std;

bool check(string& s)
{
    while (s != "ABC") {
        int N = s.size(), p = 0;
        string ns;
        for (int i = 0; i < N; i++) {
            if (i < N - 2 && s.substr(i, 3) == "ABC") {
                i += 2;
                ns += "#";
                p++;
            } else {
                ns += s[i];
            }
        }

        if (p == 0) return 0;
        vector<bool> exist(3);
        for (int i = 0; i < (int)ns.size(); i++) {
            if (ns[i] == '#') continue;
            exist[ns[i] - 'A'] = 1;                
        }

        if (exist[0] + exist[1] + exist[2] != 2) return 0;
        char c = (exist[0] == 0 ? 'A' : exist[1] == 0 ? 'B' : 'C');
        for (int i = 0; i < (int)ns.size(); i++) {
            if (ns[i] == '#') {
                ns[i] = c;
            }
        }
        s = ns;
    }
    return 1;
}

int main()
{
    string s;
    cin >> s;
    cout << (check(s) ? "Yes" : "No") << endl;
    return 0;
}
