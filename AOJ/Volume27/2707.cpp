#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, k;
    cin >> n >> k;
    long long res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += res / (k - 1) + 1;
    }
    cout << res << endl;
    return 0;
}
