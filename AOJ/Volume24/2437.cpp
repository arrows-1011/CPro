#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 55;
constexpr int MOD = ((1e9) + 7);

int Na, Nt, Ng, Nc;
int mem[MAX][MAX][MAX][MAX];

int solve(int na, int nt, int ng, int nc,
          int idx, const vector<int>& v)
{
    if (idx == (int)v.size()) {
        return (na == Na && nt == Nt && ng == Ng && nc == Nc); 
    }
    
    int& res = mem[na][nt][ng][nc];
    if (res != -1) return res;
    res = 0;
    for (int i = 0; i < 4; i++) {
        if (!(v[idx] >> i & 1)) continue;            
        switch (i) {
            case 0:
                if (na < Na) {
                    res += solve(na + 1, nt, ng, nc, idx + 1, v);
                }                    
                break;
                
            case 1:
                if (nt < Nt) {
                    res += solve(na, nt + 1, ng, nc, idx + 1, v);
                }                    
                break;
                
            case 2:
                if (ng < Ng) {
                    res += solve(na, nt, ng + 1, nc, idx + 1, v);
                }                    
                break;
                
            case 3:
                if (nc < Nc) {
                    res += solve(na, nt, ng, nc + 1, idx + 1, v);
                }                    
                break;
        }
        res %= MOD;
    }    
    return res;
}

int to_num(char ch)
{
    if (ch == 'A') return 0;
    if (ch == 'T') return 1;
    if (ch == 'G') return 2;
    return 3;
}

map<string, vector<string>> mp;

vector<int> make(const string& s)
{
    vector<int> res;
    if (s[0] == '[') {
        int S = 0;
        for (int i = 1; i < (int)s.size() - 1; i++) {
            S |= (1 << to_num(s[i]));
        }            
        res.emplace_back(S);
    } else {        
        for (const auto& next : mp[s]) {
            auto r = make(next);
            res.insert(res.end(), r.begin(), r.end());
            if ((int)res.size() > Na + Nt + Nc + Ng) {
                break;
            }
        }
    }
    return res;
}

int main()
{
    int m;
    cin >> Na >> Nt >> Ng >> Nc >> m;
    cin.ignore();
        
    vector<string> name(m);
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss >> name[i]; name[i].erase(name[i].size() - 1);
        while (ss >> s) {
            mp[name[i]].emplace_back(s);
        }
    }

    auto v = make(name[0]);
    memset(mem, -1, sizeof(mem));
    cout << solve(0, 0, 0, 0, 0, v) << endl;
    return 0;
}
