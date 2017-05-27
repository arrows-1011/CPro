#include <iostream>
#include <cctype>

int num;

const char *solve(const char *p, int idx)
{
    while (*p != '\0' && *p != ')') {
        int n = 1;
        if (isdigit(*p)) {        
            n = 0;
            while (isdigit(*p)) {
                n *= 10;                
                n += *p - '0';
                ++p;
            }
        }
        if (isalpha(*p)) {
            for (int i = 0; i < n; i++) {
                if (num++ == idx) {
                    throw *p;
                }
            }
            ++p;            
        } else if (*p == '(') {
            ++p;
            const char *q = p;
            for (int i = 0; i < n; i++) {
                p = solve(q, idx);
            }
            ++p;
        }        
    }       
    return p;
}

char find_char(const std::string &s, int idx)
{
    try {
        num = 0;
        solve(s.c_str(), idx);
    } catch (char ch) {
        return ch;
    }
    return '0';
}

int main()
{
    std::string s;
    int idx;
    while (1) {
        std::cin >> s >> idx;
        if (s == "0" && idx == 0) {
            break;
        }
        
        std::cout << find_char(s, idx) << std::endl;
    }
    return 0;
}
