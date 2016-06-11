#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[4], b[2];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> b[i];
    }

    sort(a, a + 4, greater<int>());
    sort(b, b + 2, greater<int>());

    cout << a[0] + a[1] + a[2] + b[0] << endl;
    return 0;
}
