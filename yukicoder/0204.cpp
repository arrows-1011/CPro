#include <iostream>

using namespace std;

int main()
{
    int D;
    string s, t;
    cin >> D;
    cin >> s; t += s;
    cin >> s; t += s;

    for (int i = 0; i < D; i++) {
        t = "x" + t;
    }
    for (int i = 0; i < D; i++) {
        t = t + "x";
    }
    
    int res = 0;
    for (int d = 0; d <= D; d++) {
        for (int i = 0; i < 14 + 2 * d; i++) {
            int l = i, r = i + d;
            bool ok = 1;
            for (int j = l; j < r; j++) {
                if (t[j] == 'o') {
                    ok = 0;
                    break;
                }
            }
            
            if (!ok) continue;
            
            int sum = 0;
            for (int j = 0; j <= 14 + 2 * d; j++) {
                if (t[j] == 'o' || (l <= j && j < r)) {
                    sum++;
                } else {
                    sum = 0;
                }
                res = max(res, sum);
            }
        }
    }
    cout << res << endl;
    return 0;
}
