#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    
    int T = 0;
    if (A < 0)  T += -A * C;
    if (A <= 0) T += D;
    T += min(B - A, B) * E;

    cout << T << endl;
    return 0;
}
