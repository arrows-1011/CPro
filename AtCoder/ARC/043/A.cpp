#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    double A, B;
    cin >> N >> A >> B;
    vector<ll> S(N);
    double sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        sum += S[i];
    }
    sort(S.begin(), S.end());
    if (S[N-1] == S[0]) {
        cout << -1 << endl;
    } else {         
        double P = B / (double)(S[N-1] - S[0]);
        double Q = A - P * sum / N;
        printf("%.8f %.8f\n", P, Q);
    }
    return 0;
}
