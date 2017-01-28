#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        sum += C[i];
    }

    sum /= 10;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (C[i] <= sum) {
            cnt++;
        }
    }
    cout << cnt * 30 << endl;
    return 0;
}

