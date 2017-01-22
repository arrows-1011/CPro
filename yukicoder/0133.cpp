#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    int win = 0, cnt = 0;
    do {
        int w = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > B[i]) w++;
        }
        if (w > N / 2) {
            win++;
        }
        cnt++;
    } while (next_permutation(A.begin(), A.end()));
    
    printf("%.10f\n", (double)win / cnt);
    return 0;
}
