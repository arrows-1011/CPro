#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll N, T, A, t = 0, sum = 0;
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (t <= A) {          
            sum += T;
            t = A + T;            
        } else {
            sum += A + T - t;
            t = A + T;
        }
    }
    cout << sum << endl;
    return 0;
}
