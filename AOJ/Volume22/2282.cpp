#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (1<<29)
 
int main()
{
    int n, m;
    while (cin >> n >> m, n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; ; j++) {
                int c = a[i] * j;
                if (c > m) break;
                b[i] = c;
            }      
        }
        int bmin = *min_element(b.begin(), b.end());
 
        vector<int> num;
        for (int i = 0; i < n; i++) {
            if (bmin == b[i]) {
                num.push_back(i);
            }
        }
     
        if (num.size() == 1) {
            cout << num[0] + 1 << endl;
        } else {
            int amin = INF;
            for (int i = 0; i < (int)num.size(); i++) {
                amin = min(amin, a[num[i]]);
            }
            vector<int> num2;
            for (int i = 0; i < (int)num.size(); i++) {
                if (amin == a[num[i]]) {
                    num2.push_back(num[i]);
                }
            }
            if (num2.size() == 1) {
                cout << num2[0] + 1 << endl;
            } else {
                cout << n << endl;
            }
        }
    } 
    return 0;
}
