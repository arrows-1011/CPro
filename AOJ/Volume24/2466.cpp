#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    
    std::vector<int> v(s.size());
    int depth = 0;
    long long res = 0;
    
    for (char c : s) {
        res += v[depth];
        v[depth]++;
        if (c == '(') {
            depth++;
        } else {
            depth--;
        }
    }
    std::cout << res << std::endl;
    return 0;
}
