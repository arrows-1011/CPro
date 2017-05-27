#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<int> count(26);
    for (char c : s) {
        count[c - 'a']++;
    }

    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += count[i] % 2;
    }
    std::cout << sum / 2 << std::endl;
    return 0;
}
