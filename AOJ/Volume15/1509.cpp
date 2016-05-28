#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, e, na, nb, nc;
    while (cin >> a >> b >> c >> d >> e, a) {
        cin >> na >> nb >> nc;
        int cost = 0;
        if (nc >= d) {
            cost += nc * e;
            nc = 0;
        }

        if (na + nb + nc >= d) {
            int T = d - nc, j = 0, k = 0;
            
            while (j < nb && T > 0) {
                T--; j++;
            }

            while (k < na && T > 0) {
                T--; k++;
            }
            
            int t = a * na + b * nb + c * nc;
            int t2 = (k + j + nc) * e + a * (na - k) + b * (nb - j);            
            cost += min(t, t2);
        } else {
            int t = a * na + b * nb + c * nc;
            int t2 = d * e;
            cost += min(t, t2);
        }
        cout << cost << endl;
    }
    return 0;
}
