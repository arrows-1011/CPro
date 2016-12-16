#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int res = (1 << 29);
    for (int i = -100; i <= 100; i++) {
        int total_cost = 0;
        for (int j = 0; j < N; j++) {
            total_cost += (i - a[j]) * (i - a[j]);
        }
        res = min(res, total_cost);
    }
    cout << res << endl;
    return 0;
}
