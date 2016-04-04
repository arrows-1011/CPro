#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;

class Calc {
  private:
    string str;
    vector<char> p;
    string::iterator it;

  public:
    Calc (string str, vector<char> p) {
        this->str = str;
        this->p   = p;
        it = this->str.begin();
    }

    ll get_val(ll a, char op, ll b)
    {
        switch (op) {
            case '*':
                return a * b;
            case '+':
                return a + b;
            case '-':
                return a - b;                
        }
    }

    ll f0(int pt)
    {
        ll res = 0;
        if (*it == '(') {
            ++it;
            if (pt == 0) {
                res = f3(0);
            } else if (pt <= 2) {
                res = f2(pt);   
            } else {
                res = f1(3);
            }
            ++it;
        } else {
            while (isdigit(*it)) {
                res *= 10LL;
                res += (ll)(*it - '0');
                ++it;
            }
        }
        return res;
    }

    ll f1(int pt)
    {
        ll res = f0(pt);
        while (*it == p[0] ||
               (pt >= 2 && *it == p[1]) ||
               (pt >= 3 && *it == p[2])) {
            
            if (*it == p[0]) {
                ++it;            
                res = get_val(res, p[0], f0(pt));
            } else if (pt >= 2 && *it == p[1]) {
                ++it;
                res = get_val(res, p[1], f0(pt));
            } else if (pt >= 3 && *it == p[2]) {
                ++it;
                res = get_val(res, p[2], f0(pt));
            }            
        }
        return res;
    }

    ll f2(int pt)
    {
        ll res = f1(pt);
        while ((pt <= 1 && *it == p[1]) ||
               (pt >= 1 && *it == p[2])) {
            
            if (pt <= 1 && *it == p[1]) {
                ++it;
                res = get_val(res, p[1], f1(pt));                                
            } else if (pt >= 1 && *it == p[2]) {
                ++it;
                res = get_val(res, p[2], f1(pt));                
            }
                   
        }
        return res;
    }

    ll f3(int pt)
    {
        ll res = f2(0);
        while (*it == p[2]) {
            ++it;
            res = get_val(res, p[2], f2(0));
        }
        return res;
    }
};

int main()
{
    string str;
    cin >> str;      
    vector<char> p = {'*', '+', '-'};
    ll res = LLONG_MIN;    
    do {
        for (int i = 0; i < 4; i++) {
            Calc  c(str, p);
            ll r = -1;
            if (i == 0) {
                r = c.f3(0);
            } else if (i <= 2) {
                r = c.f2(i);
            } else {
                r = c.f1(3);
            }
            res = max(res, r);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << res << endl;    
    return 0;
}
