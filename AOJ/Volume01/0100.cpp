#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n;
     
    while (cin >> n, n) {
        int cnt = 0;
        unsigned long long int s[4002] = {0}, gs[4002] = {0};

        int t, cost, num;

        for (int i = 0; i < n; i++) {
            cin >> num >> t >> cost;
            s[num] += t*cost;
            gs[i] = num;
        }
         
	for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(gs[i] == gs[j] && i < j) {
                    gs[j] = 4001;
                }
            }
        }
         
        for (int i = 0; i < n; i++) {
            if (s[gs[i]] >= 1000000) {
                cout << gs[i] << endl;
                cnt++;
            }
        }
        if (!cnt) cout << "NA" << endl;
    }
    return 0;
}
