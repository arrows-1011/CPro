#include <iostream>

int main()
{
    int N, d;
    std::cin >> N >> d;
    int p, res = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> p;
        res += std::max(0, p - d);
    }
    if (res == 0) {
        std::cout << "kusoge" << std::endl;
    } else {
        std::cout << res << std::endl;
    }    
    return 0;
}
