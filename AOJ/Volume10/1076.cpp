#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
 
ull sum(int x)
{
    return x * (x + 1ULL) / 2ULL;
}
 
ull lcm(ull a, ull b)
{
    return a / (ull)__gcd(a, b) * b;
}
 
int main()
{
    ull n, m;
    while (cin >> n >> m, n) {
        vector<ull> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        int a = 0, b = 0;
        ull N = n;
        double res = sum(n);
        for (int i = 1; i < (1<<m); i++) {            
            int cnt = 0;
            ull l = 1;
            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    cnt++;
                    l = lcm(l, p[j]);
                }
            }
            if (cnt & 1) {
                N -= n/l;
            } else {
                N += n/l;
            }
            l = l * sum(n / l);
            if (cnt & 1) {    
                res -= l;
            } else {
                res += l;
            }
        }
        if (res == 0) {
            printf("%.10f\n", 0);      
        } else {
            printf("%.10f\n", res/N);
        }
    }
    return 0;
}
