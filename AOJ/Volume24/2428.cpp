#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

class Calc {
  private:
    int N, idx;
    string s;
    
  public:
    Calc (const string& s) : s{s} {
        idx = 0;
        N = s.size();
    }

    static bool is_op(char c)
    {
        return (c == '+' || c == '-' || c == '*');   
    }

    bool check_range(int x)
    {
        return (0 <= x && x < 1024);
    }
    
    int num()
    {
        int res = 0, p = 0;
        while (isdigit(s[idx])) {
            if (p > 10 && s[idx] == '1') return -1;
            res *= 2;
            res += (s[idx] - '0');
            p++;
            ++idx;
        }        
        return (check_range(res) ? res : -1);
    }

    bool check_op(int cur)
    {
        int p = 0;
        for (int i = cur + 1; i < N; i++) {
            if (s[i] == '(') p++;
            if (s[i] == ')') p--;
            if (p == 0 && is_op(s[i])) return 1;
            if (p < 0) break;
        }
        return 0;
    }
    
    int fact()
    {
        int ret = -1;
        if (s[idx] == '(') {
            if (!check_op(idx)) throw 0;
            ++idx;
            ret = expr();
            ++idx;
        } else {
            ret = num();
        }
        if (!check_range(ret)) throw 0;         
        return ret;
    }

    int term()
    {
        int ret = fact();
        while (s[idx] == '*') {
            ++idx;
            ret *= fact();
            if (!check_range(ret)) throw 0; 
        }
        return ret;
    }

    int expr()
    {
        int ret = term();

        while (s[idx] == '+' || s[idx] == '-') {
            if (s[idx] == '+') {
                ++idx;
                ret += term();
            } else {
                ++idx;
                ret -= term();
            }
            if (!check_range(ret)) throw 0; 
        }
        return ret;
    }
};

vector<int> get_marks(int x, int n)
{
    vector<int> res;
    while ((int)res.size() != n) {
        res.emplace_back(x % 7);
        x /= 7;
    }
    return res;
}

bool valid(const string& s)
{
    int p = 0, N = s.size();
    for (int i = 0; i < N; i++) {
        if (Calc::is_op(s[i])) {
            if (i == 0 || i == N - 1) return 0;
            if (s[i - 1] == '(' || Calc::is_op(s[i - 1])) {
                return 0;
            }
            if (s[i + 1] == ')' || Calc::is_op(s[i + 1])) {
                return 0;
            }
        }

        if (s[i] == '(') {
            if (i == N - 1) return 0;
            if (i > 0 && (isdigit(s[i - 1]) || s[i - 1] == ')')) {
                return 0;
            }
        }
        
        if (s[i] == ')') {
            if (i == 0) return 0;
            if (i < N - 1 && (isdigit(s[i + 1]) || s[i + 1] == '(')) {
                return 0;
            }
        }
            
        if (s[i] == '(') p++;
        if (s[i] == ')') p--;
        if (p < 0) return 0;

        for (int j = i + 1; j < N; j++) {
            if (s[i] == '(' && s[j] == ')' && j - i < 4) {
                return 0;
            }
        }
    }
    return (p == 0);
}

int solve(string& s)
{
    int N = s.size();
    vector<int> dot;
    for (int i = 0; i < N; i++) {
        if (s[i] == '.') {
            dot.emplace_back(i);
        }
    }
    int n = dot.size();
    if (n == 0) {
        if (!valid(s)) return -1;
        Calc calc(s);
        int res = -1;
        
        try {
            res = calc.expr();
        } catch (...) {}
        
        return res;
    }

    constexpr char mark[] = {'0', '1', '+', '-', '*', '(', ')'};
    
    int res = -1;
    vector<int> p(n);
    for (int i = 0; i < pow(7, n); i++) {
        auto mark_idx = get_marks(i, n);
        string tmp = s;
        for (int j = 0; j < n; j++) {
            s[dot[j]] = mark[mark_idx[j]];
        }
        if (valid(s)) {
            Calc calc(s);
            try {
                res = max(res, calc.expr());
            } catch (...) {}
        }
        s = tmp;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
