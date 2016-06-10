#include <bits/stdc++.h>

using namespace std;

bool c(int x, int M, vector<int> &a)
{
    int N = a.size();
    int cnt = 0, sum = 0;
    for (int i = 0; i < N; ) {
        if (a[i] > x) return 0;

        while (i < N && sum < x) {
            sum += a[i++];            
        }
        if (sum > x) {
            i--;
        }                 
        cnt++;
        sum = 0;
    }
    return (cnt <= M);
}

int main()
{
    int M, N;
    while (cin >> M >> N, M) {
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int l = 0, r = 1e9;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (c(mid, M, a)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << endl;
    }
    return 0;
}
