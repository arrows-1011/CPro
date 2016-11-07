#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = (1 << 29);

int main()
{
    int N, M;
    cin >> N >> M;
    string d;
    vector<int> sumL(N + 2), sumR(N + 2);
    for (int i = 0; i < M; i++) {
        cin >> d;
        for (int i = 1; i <= N; i++) {
            sumL[i] += (d[i - 1] == 'E');
        }

        for (int i = N; i >= 1; i--) {
            sumR[i - 1] += (d[i - 1] == 'W');
        }        
    }

    for (int i = 1; i <= N; i++) {
        sumL[i] += sumL[i - 1];
    }

    for (int i = N; i >= 1; i--) {
        sumR[i - 1] += sumR[i];
    }
    
    int mini = INF, num = -1;
    for (int i = 0; i <= N; i++) {
        if (sumL[i] + sumR[i] < mini) {
            mini = sumL[i] + sumR[i];
            num = i;
        }
    }
    cout << num << " " << num + 1 << endl;
    return 0;
}
