#include <iostream>
#include <cmath>
 
int main()
{
    int N, K;
    std::cin >> N >> K;
    int res = K * pow(K - 1, N - 1);;
    std::cout << res << std::endl;
    return 0;
}
