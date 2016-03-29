#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> v)
{
    int xor_val = v[0];
    for (int i = 1; i < (int)v.size(); i++) {
        xor_val ^= v[i];
    }
    return (xor_val == 0);
}

bool f(int n, int k, int a[5][5], vector<int> v)
{
    if (n == -1) {
        return check(v);
    }
    for (int i = 0; i < k; i++) {
        v.push_back(a[n][i]);
        if (f(n-1, k, a, v)) {
            return 1;
        }
        v.pop_back();
    }
    return 0;
}

int main()
{
    int N, K, a[5][5];
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> v;
    cout << (f(N-1, K, a, v) ? "Found" : "Nothing") << endl;
    return 0;
}
