#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (A * B <= C * D ? C * D : A * B) << endl;
    return 0;
}
