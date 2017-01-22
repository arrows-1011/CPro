#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    string S;
    cin >> N >> K >> S; K--;
    int p = 0;
    if (S[K] == '(') {
        for (int i = K; i < N; i++) {
            if (S[i] == '(') {
                p++;
            } else {
                p--;
            }
            if (p == 0) {
                cout << i + 1 << endl;
                break;
            }
        }
    } else {
        for (int i = K; i >= 0; i--) {
            if (S[i] == ')') {
                p++;
            } else {
                p--;
            }
            if (p == 0) {
                cout << i + 1 << endl;
                break;
            }
        }
    }        
    return 0;
}
