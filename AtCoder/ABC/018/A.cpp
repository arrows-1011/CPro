#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(3), b;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    b = a;
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] == b[j]) {
                cout << j+1 << endl;
                break;
            }
        }
    }

    return 0;
}
