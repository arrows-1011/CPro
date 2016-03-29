#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    for (size_t i = 0; i < s.size(); ) {
        size_t j = i;
        while (j < s.size() && s[i] == s[j]) {
            ++j;
        }
        std::cout << s[i] << j-i;
        i = j;
    }
    std::cout << std::endl;
    return 0;
}
