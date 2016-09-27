#include <bits/stdc++.h>

using namespace std;

int main()
{
    double R0, W0, C, R;
    while (cin >> R0 >> W0 >> C >> R, (R0 > 0)) {        
        for (int X = 0; ; X++) {
            if ((R0 + X * R) / C - W0 >= 0) {
                cout << X << endl;
                break;
            }
        }
    }        
    return 0;
}
