#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[3], b[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    
    sort(a, a+3);
    int res = 0;
    
    do {
        res = max(res, (a[0]/b[0]) * (a[1]/b[1]) * (a[2]/b[2]));
    } while (next_permutation(a, a+3));

    cout << res << endl;
    return 0;
}
