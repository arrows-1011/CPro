#include <bits/stdc++.h>

using namespace std;
 
bool c(int x)
{
    int e = x % 10; x /= 10;
    while (x > 0) {
        if (x % 10 + 1 != e) {
            return 0;
        }
        e = x % 10;
        x /= 10;
    }
    return 1;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int res = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int b = a[i] * a[j];
            if (c(b) && res < b) res = b;
        }
    }
    cout << res << endl;
    return 0;
}
