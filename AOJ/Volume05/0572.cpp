#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    vector<int> a(A), b(B);
    for (int i = 0; i < A; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> b[i];
    }

    int res = 0;
    for (int i = 0; i < B; i++) {
        int p = i;
        for (int j = 0; j < A; j++) {
            if (b[p] == a[j]) {
                p++;
            }
        }
        res = max(res, p - i);
    }
    cout << res << endl;
    return 0;
}
