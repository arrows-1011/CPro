#include <iostream>
#include <algorithm>

int main()
{
    int a[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a+3);
    std::cout << a[1] << std::endl;
    return 0;
}
