#include <iostream>
#include <set>
#include <vector>

int min;
std::string res;

void dfs(int depth, std::string s,
           const std::set<std::string> &st)
{
    if (depth == 4) {
        if (s.empty() || st.count(s)) {
            return;
        }
        
        int size = s.size();
        if (size < min) {
            min = size;
            res = s;
        } else if (size == min) {
            res = std::min(res, s);
        }
        return;
    }

    dfs(depth + 1, s, st);    
    for (char c = 'a'; c <= 'z'; c++) {
        dfs(depth + 1, s + c, st);
    }    
}

int main()
{
    int N;   
    std::cin >> N;    
    
    std::set<std::string> st; 
    for (int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;
        int size = S.size();
        for (int j = 0; j < size; j++) {
            for (int k = 1; k <= 4; k++) {
                if (j + k > size) break;
                st.insert(S.substr(j, k));
            }
        }
    }

    min = 5;    
    std::string s;
    dfs(0, s, st);
    std::cout << res << std::endl;
    
    return 0;
}
