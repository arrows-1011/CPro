#include <bits/stdc++.h>

using namespace std;

string change_string(string &s)
{
    map<char, char> mp = {
        {'b', '1'}, {'c', '1'},
        {'d', '2'}, {'w', '2'},
        {'t', '3'}, {'j', '3'},
        {'f', '4'}, {'q', '4'},
        {'l', '5'}, {'v', '5'},
        {'s', '6'}, {'x', '6'},
        {'p', '7'}, {'m', '7'},
        {'h', '8'}, {'k', '8'},
        {'n', '9'}, {'g', '9'},
        {'z', '0'}, {'r', '0'}
    };
    
    string res;
    for (int i = 0; i < (int)s.size(); i++) {
        if (!isalpha(s[i])) continue;
        s[i] = tolower(s[i]);
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o' ||
            s[i] == 'y') {
            continue;
        }
        res += mp[s[i]];
    }
    return res;
}

int main()
{
    int N;
    string w;
    vector<string> res;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> w;
        string tw = change_string(w);
        if (tw.size() > 0) {
            res.push_back(tw);
        }
    }
    for (int i = 0; i < (int)res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}
