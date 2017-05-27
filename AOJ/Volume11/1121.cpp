#include <iostream>
#include <vector>
#include <sstream>

bool match(std::string &s, const std::string &t)
{
    int N = s.size(), M = t.size();
    if (N < M) {
        return false;
    }

    for (int i = 0; i < M; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }

    s = s.substr(M);
    
    return true;
}

int main()
{
    constexpr int SIZE = 26 + 12;
    const std::string let[SIZE] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
        "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
        "u", "v", "w", "x", "y", "z",
        "ld", "mb", "mp", "nc", "nd", "ng", "nt", "nw", "ps", "qu",
        "cw", "ts"
    };

    std::vector<std::vector<int>> count(SIZE, std::vector<int>(SIZE, 0));
    
    int N;
    std::cin >> N;
    std::cin.ignore();
    for (int i = 0; i < N; i++) {
        std::string s;
        std::getline(std::cin, s);
        std::stringstream ss{s};
        while (ss >> s) {
            int prev = -1;
            while (!s.empty()) {
                for (int j = SIZE - 1; j >= 0; j--) {
                    if (match(s, let[j])) {
                        if (prev != -1) {
                            count[prev][j]++;                         
                        }
                        prev = j;
                        break;
                    }
                }
            }            
        }        
    }
    
    for (int i = 0; i < SIZE; i++) {
        int max = -1, mi = -1;
        for (int j = 0; j < SIZE; j++) {
            if (count[i][j] > max) {
                max = count[i][j];
                mi = j;
            }
        }
        std::cout << let[i] << " " << let[mi] << " " << count[i][mi] << std::endl;
    }
    return 0;
}
