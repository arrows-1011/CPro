#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> card(K, vector<int>(N/2));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N/2; j++) {
            cin >> card[i][j];
            card[i][j]--;
        }
    }
    
    random_device rd;
    mt19937 mt(rd());
    bool finished = 0;
    while (!finished) {
        finished = 1;
        
        vector<int> seq(N);
        for (int i = 0; i < N; i++) {
            seq[i] = mt() % 2;
        }
        
        for (int i = 0; i < K; i++) {
            int sum = 0;
            for (int j = 0; j < N/2; j++) {
                sum += seq[card[i][j]];
            }
            if (sum < N/8 || sum > 3*N/8) {
                finished = 0;
                break;
            }
        }

        if (finished) {
            for (int i = 0; i < N; i++) {
                cout << seq[i];
            }
            cout << endl;
        }
    }
    return 0;
}
