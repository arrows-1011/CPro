#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    std::string s;
    while (1) {
        std::cin >> s;
        if (s == "#") {
            break;
        }

        bool ok = 0;
        std::stringstream ss{s};        
        while (std::getline(ss, s, '|')) {
            std::string t = s.substr(1, s.size() - 2);
            std::stringstream tt{t};
            
            std::vector<int> v(256, 0);
            while (std::getline(tt, s, '&')) {
                if (s[0] == '~') {
                    v[s[1]] |= 2;
                } else {
                    v[s[0]] |= 1;
                }
            }
            
            bool f = 1;
            for (int i = 0; i < 256; i++) {
                if (v[i] == 3) {
                    f = 0;
                }
            }
            ok |= f;
        }
        std::cout << (ok ? "yes" : "no") << std::endl;
    }
    return 0;
}
