#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (N & 1) {
        cout << a[N / 2] << endl;
    } else {
        printf("%.15f\n", (a[N / 2 - 1] + a[N / 2]) / 2.0);
    }
    return 0;
}
