#include <iostream>
#include <vector>

using namespace std;

bool is_kadomatsu(int A, int B, int C)
{
    if (A == B || A == C || B == C) {
        return 0;
    }
        
    if (A > B && B < C) return 1;
    if (A < B && B > C) return 1;
    return 0;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 2; i < N; i++) {
        if (is_kadomatsu(a[i - 2], a[i - 1], a[i])) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
