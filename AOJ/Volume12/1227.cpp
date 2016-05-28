#include <bits/stdc++.h>

using namespace std;

char to_num(char c)
{
    if (c <= 'c') return '2';
    if (c <= 'f') return '3';
    if (c <= 'i') return '4';
    if (c <= 'l') return '5';
    if (c <= 'o') return '6';
    if (c <= 's') return '7';
    if (c <= 'v') return '8';
    return '9';
}

vector<string> w, v;

void dfs(string &seq, int idx, vector<string> words)
{
    int size = seq.size();
    if (idx == size) {
        for (int i = 0; i < (int)words.size(); i++) {
            if (i > 0) cout << " ";
            cout << words[i];
        }
        cout << "." << endl;
        return;
    }

    for (int i = 0; i < (int)v.size(); i++) {
        int len = v[i].size();
        if (idx + len <= size) {
            bool ok = 1;
            for (int j = 0; j < len; j++) {
                if (seq[idx + j] != v[i][j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                words.push_back(w[i]);
                dfs(seq, idx + len, words);
                words.pop_back();
            }
        }
    }
}

void init()
{
    w.clear();
    v.clear();
}

int main()
{
    int N;
    while (cin >> N, N) {
        init();
        string s, seq;
        for (int i = 0; i < N; i++) {
            cin >> s;
            string t;
            for (int j = 0; j < (int)s.size(); j++) {
                t += to_num(s[j]);
            }
            w.push_back(s);
            v.push_back(t);
        }
        cin >> seq;
        dfs(seq, 0, vector<string>());
        cout << "--" << endl;
    }
    return 0;
}
