#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x)
{
    if (x <= 1) return 0;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int N;
    cin >> N;
    cout << (is_prime(N) ? "YES" : "NO") << endl;
    return 0;
}
