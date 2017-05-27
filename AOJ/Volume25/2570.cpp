#include <iostream>

using ll = long long;
constexpr ll MOD = (1e9) + 7;

class Parser {
  private:
    std::string s;
    std::string::const_iterator it;
    
  public:
    Parser (std::string s) {
        this->s = s;
        it = this->s.begin();
    }

    ll number()
    {
        ll res = 0;
        while (isdigit(*it)) {
            res *= 10;
            res += *it - '0';
            ++it;
        }
        return res;
    }
    
    ll term()
    {
        ll res = 0;
        if (isdigit(*it)) {
            res = number();
        } else if (*it == 'S') {
            it += 2; // S <            
            res = expr() % MOD;            
            res = (res * res) % MOD;
            ++it; // >
        }
        return res;
    }

    bool is_term(char ch)
    {
        return (isdigit(ch) || ch == 'S');
    }

    void shift(ll &x, ll y)
    {
        for (ll i = 0; i < y; i++) {
            if (x == 0) {
                return;
            }
            x >>= 1;
        }
    }
    
    ll expr()
    {
        ll res = term();
        while (*it == '>' && *(it + 1) == '>' && is_term(*(it + 2))) {
            it += 2;
            shift(res, term());            
            res %= MOD;
        }
        return res;
    }
};

std::string remove_spaces(const std::string &s)
{
    std::string res;
    for (char c : s) {
        if (c != ' ') {
            res += c;
        }
    }
    return res;
}

int main()
{
    std::string s;
    while (1) {
        std::getline(std::cin, s);
        if (s == "#") {
            break;
        }
        s = remove_spaces(s);
        
        Parser p{s};
        std::cout << p.expr() << std::endl;
    }
    return 0;
}
