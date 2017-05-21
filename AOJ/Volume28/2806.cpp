#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int lcm(int a, int b)
{
    return a / std::__gcd(a, b) * b;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int res = 0;
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0, j = 0; i < lcm(N, M); i++, j++) {
        max = std::max(max, A[i % N]);
        min = std::min(min, A[i % N]);
        
        if (j + 1 == M) {
            res += max - min;
            j = -1;
            max = INT_MIN;
            min = INT_MAX;
        }
    }
    std::cout << res << std::endl;    
    return 0;
}
