#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, l = 0, r = 0;
    cin >> w;
    for (int i = 0; ; i++) {        
        r += pow(3, i);
        if (l <= w && w <= r) {
            w -= pow(3, i);
            r -= pow(3, i);
            cout << '+';
            for (int j = i - 1; j >= 0; j--) {
                if (r - pow(3, j) < abs(w)) {
                    if (w > 0) {
                        w -= pow(3, j);
                        cout << '+';
                    } else {
                        w += pow(3, j);
                        cout << '-';
                    }
                } else {
                    cout << 0;
                }
                r -= pow(3, j);
            }
            cout << endl;
            break;
        }
        l = r + 1;
    }    
    return 0;
}
