#include <iostream>

int main()
{
    int N, K;
    std::cin >> N >> K;
    int min = 1145, max = -14;
    for (int i = 0; i < N; i++) {
        int n;
        std::cin >> n;
        
        min = std::min(min, n);
        max = std::max(max, n);
    }
    std::cout << max - min << std::endl;
    return 0;
}
