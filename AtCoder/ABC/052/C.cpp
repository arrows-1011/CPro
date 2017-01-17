#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    map<int, int> pf;
    for (int i = 2; i <= N; i++) {        
        int n = i;
        for (int j = 2; j <= n; j++) {
            while (n % j == 0) {
                ++pf[j];
                n /= j;
            }
        }
    }
    
    long long res = 1;
    constexpr long long MOD = ((1e9) + 7);
    
    for (auto& v : pf) {
        res *= (v.second + 1);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
