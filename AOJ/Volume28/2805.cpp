#include <iostream>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(M);
    for (int i = 0; i < M; i++) {
        std::cin >> a[i];
    }
    std::cout << N - M - 1 << std::endl;
    return 0;
}
