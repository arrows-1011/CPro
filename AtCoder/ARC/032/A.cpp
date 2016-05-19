#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
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
    cout << (isPrime(N*(N+1)/2) ? "WANWAN" : "BOWWOW") << endl;
    return 0;
}
