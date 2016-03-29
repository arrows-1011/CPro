#include <iostream>

using namespace std;

int main()
{
    int A, B, C, K, S, T;
    cin >> A >> B >> C >> K >> S >> T;
    int fee = 0;
    fee += (S + T >= K ? (A - C)*S + (B - C)*T : A*S + B*T);
    cout << fee << endl;
    return 0;
}
