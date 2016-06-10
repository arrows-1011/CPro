#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000
 
int main()
{
    int m, n;
     
    while (cin >> m, m) {
        cin >> n;
        int cnt = 0;
        for (int i = m; i <= n; i++) {
            int tmp = i;
            while (!(tmp%2) || !(tmp%3) || !(tmp%5)) {
                if (!(tmp%2)) tmp /= 2;
                else if (!(tmp%3)) tmp /= 3;
                else if (!(tmp%5)) tmp /= 5;
            }
            if (tmp == 1) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
