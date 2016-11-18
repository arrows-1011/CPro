#include <iostream>
#include <set>
#include <cctype>
#include <vector>
#include <cstring>

using namespace std;

string S;

bool is_op(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool is_num(int L, int R)
{
    for (int i = L; i <= R; i++) {
        if (!isdigit(S[i])) return 0;
    }
    return 1;
}

int num(int L, int R)
{
    int res = 0;
    for (int i = L; i <= R; i++) {
        res *= 10;
        res += (S[i] - '0');
    }
    return res;
}

int near(int L, int R)
{
    int p = 0;
    for (int i = L; i <= R; i++) {
        if (S[i] == '(') p++;
        if (S[i] == ')') p--;
        if (p == 0) return i;
    }
    return -1;
}

set<int> expr(int L, int R)
{
    set<int> res;
    
    if (is_num(L, R)) return {num(L, R)};
    
    int nR = near(L, R);
    if (nR == R && S[L] == '(' && S[R] == ')') {
        return expr(L + 1, R - 1);
    }
    
    for (int i = L; i <= R - 1; i++) {
        char c = S[i];
        
        if (!is_op(c)) continue;        
        
        auto l = expr(L, i - 1);
        auto r = expr(i + 1, R);
        
        for (int lv : l) {
            for (int rv : r) {
                switch (c) {
                    case '+':
                        res.insert(lv + rv);
                        break;
                    case '-':
                        res.insert(lv - rv);
                        break;
                    case '*':
                        res.insert(lv * rv);
                        break;
                    case '/':
                        if (rv != 0) {
                            res.insert(lv / rv);                            
                        }                            
                        break;
                }
            }
        }
    } 
    return res;
}

void solve()
{
    int N = S.size();
    cout << expr(0, N - 1).size() << endl;
}

int main()
{
    while (cin >> S, S != "#") {
        solve();
    }
    return 0;
}
