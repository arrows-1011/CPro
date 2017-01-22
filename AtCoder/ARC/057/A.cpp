#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll A, K;
    constexpr ll N = 2e12;
    cin >> A >> K;
    if (K == 0) {
        cout << N - A << endl;
    } else {
        ll day = 0;
        for (; A < N; day++) {
            A += 1 + K * A;            
        }
        cout << day << endl;
    }           
    return 0;
}
