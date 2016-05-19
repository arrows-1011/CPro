#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A;
    cin >> A;
    int cnt = 0;
    int size = A.size();
    for (int i = 0; i < size/2; i++) {
        if (A[i] != A[size-i-1]) {
            cnt++;
        }
    }
    if (size == 1) {
        cout << 0 << endl;
        return 0;
    }
        
    int res = 0;
    for (int i = 0; i < size; i++) {
        if (cnt == 0) {
            if (size % 2 == 1) {
                if (i != size/2) { 
                    res += 25;
                }
            } else {
                res += 25;
            }
        } else if (cnt == 1) {
            if (A[i] != A[size-i-1]) {
                res += 24;
            } else {
                res += 25;
            }
        } else {
            res += 25;
        }
    }
    cout << res << endl;
    return 0;
}
