#include <bits/stdc++.h>
  
using namespace std;
 
#define MAX 256
typedef pair<int, int> pii;
  
int n;
vector<string> e;
map<string, pii> mp;
  
int op_num(char c)
{
    switch (c) {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
    }
    return -1;
}
  
int s2i(string &s)
{
    int res;
    stringstream ss(s);
    ss >> res;
    return res;
}

int calc(int a, int op, int b)
{    
    if (op == 0) {
        return (a + b) % 256;
    } else if (op == 1) {
        return (a - b + 256) % 256;
    } else if (op == 2) {
        return (a * b) % 256;
    } else {
        return (b == 0 ? MAX : (a / b) % 256);
    }
}

bool zero_division_checker()
{
    stack<vector<int>> st;
    for (int i = 0; i < n; i++) {
        if (isdigit(e[i][0])) {
            st.push({s2i(e[i])});
        } else {
            vector<int> v;
            int op = op_num(e[i][0]);            
            if (op >= 0) {
                vector<int> vb = st.top(); st.pop();
                vector<int> va = st.top(); st.pop();
                for (int j = 0; j < (int)va.size(); j++) {
                    for (int k = 0; k < (int)vb.size(); k++) {
                        int res = calc(va[j], op, vb[k]);
                        if (res == MAX) {
                            return 0;
                        }
                        v.push_back(res);
                    }
                }
                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());
                st.push(v);
            } else {
                pii p = mp[e[i]];
                for (int j = p.first; j <= p.second; j++) {
                    v.push_back(j);
                }
                st.push(v);                
            }
        }
    }
    return 1;
}
  
int main()
{
    int m;
    cin >> m;
    string name;
    int lb, ub;
    for (int i = 0; i < m; i++) {
        cin >> name >> lb >> ub;
        mp[name] = pii(lb, ub);
    }
    cin >> n;
    e.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }
    cout << (zero_division_checker() ? "correct" : "error") << endl;
    return 0;
}
