#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, n = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        n += A[i];
    }

    if (n % N != 0) {
        cout << -1 << endl;
        return 0;
    }

    n /= N;
    int cnt = 0, sum = 0, m = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i]; m++;
        if (sum % m == 0 && sum / m == n) {
            sum = 0; m = 0;
        } else {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
