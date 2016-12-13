#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <cctype>

using namespace std;

constexpr int MAX = 1010;
constexpr int LIMIT = 50000000;

int N, line[MAX], order[MAX];
char c1[MAX], c2[MAX], c3[MAX];
int v[MAX];

int getNum(string& s)
{
    if (s == "SET") return 0;
    if (s == "ADD") return 1;
    if (s == "SUB") return 2;
    if (s == "IF")  return 3;
    return 4;
}

map<char, int> mp;

bool solve()
{
    int idx = 0, v1, v2, next;
    for (int i = 0; i < LIMIT; i++) {
        if (idx == N) return 1;
        switch (order[idx]) {
            case 0:
                if (v[idx] != -1) {
                    mp[c1[idx]] = v[idx];
                } else {
                    mp[c1[idx]] = mp[c2[idx]];
                }
                break;
            case 1:
                v1 = mp[c2[idx]];
                v2 = (v[idx] != -1 ? v[idx] : mp[c3[idx]]);
                if (v1 + v2 >= 16) return 1;
                mp[c1[idx]] = v1 + v2;
                break;
            case 2:
                v1 = mp[c2[idx]];
                v2 = (v[idx] != -1 ? v[idx] : mp[c3[idx]]);
                if (v1 - v2 < 0) return 1;
                mp[c1[idx]] = v1 - v2;
                break;
            case 3:
                next = line[v[idx]];
                if (next == -1) return 1;
                if (mp[c1[idx]] != 0) { 
                    idx = next;
                    continue;
                }
                break;
            case 4:
                return 1;
        }
        idx++;
    }
    return 0;
}

int main()
{
    int x;
    string s;
    memset(line, -1, sizeof(line));
    memset(v, -1, sizeof(v));
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> s;
        line[x] = i;
        order[i] = getNum(s);
        stringstream ss;
        switch (order[i]) {
            case 0:         
            case 3:
                cin >> c1[i] >> s;
                mp[c1[i]] = 0;
                if (isdigit(s[0])) {
                    ss << s;
                    ss >> v[i];
                } else {
                    c2[i] = s[0];
                    mp[c2[i]] = 0;
                }
                break;
            case 1:
            case 2:
                cin >> c1[i] >> c2[i] >> s;
                if (isdigit(s[0])) {
                    ss << s;
                    ss >> v[i];
                } else {
                    c3[i] = s[0];
                    mp[c3[i]] = 0;
                }
                break;
        }
    }
    if (solve()) {
        for (auto& it : mp) {
            cout << it.first << "=" << it.second << endl;
        }       
    } else {
        cout << "inf" << endl;  
    }
    return 0;
}
