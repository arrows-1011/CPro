#include <iostream>

using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    
    int res = n;
    for (int lp = 0, i = 0; lp <= n; lp += 2, i++) {
        if (lp == p || lp + 1 == p) {
            res = min(res, i);
            break;
        }
    }
    
    for (int lp = (n & 1 ? n - 1 : n), i = 0; lp >= 0; i++, lp -= 2) {
        if (lp == p || lp + 1 == p) {
            res = min(res, i);
            break;
        }
    }

    cout << res << endl;
        
    return 0;
}
