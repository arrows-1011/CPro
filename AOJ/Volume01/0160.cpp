#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n, x, y, h, w;
    while (cin >> n, n) {
        int tc = 0;
        while (n--) {
            cin >> x >> y >> h >> w;
             
            int tc1 = 0, tc2 = 0, size = x+y+h;
            bool tf1 = false, tf2 = false;
             
            if (size <= 60) tc1 = 600;
            else if (size <= 80) tc1 = 800;
            else if (size <= 100) tc1 = 1000;
            else if (size <= 120) tc1 = 1200;
            else if (size <= 140) tc1 = 1400;
            else if (size <= 160) tc1 = 1600;
            else tf1 = true;
             
            if (w <= 2) tc2 = 600;
            else if (w <= 5) tc2 = 800;
            else if (w <= 10) tc2 = 1000;
            else if (w <= 15) tc2 = 1200;
            else if (w <= 20) tc2 = 1400;
            else if (w <= 25) tc2 = 1600;
            else tf2 = true;
             
            if (tf1||tf2) continue;
            else tc += max(tc1, tc2);
        }
        cout << tc << endl;
    }
    return 0;
}
