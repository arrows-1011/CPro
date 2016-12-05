#include <iostream>

using namespace std;

int main()
{
    int L, N;
    cin >> L >> N;
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        int x, w;
        cin >> x >> w;
        cout << -x << " " << w << endl;
    }
    return 0;
}
