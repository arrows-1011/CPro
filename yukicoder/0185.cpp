#include <iostream>

using namespace std;

int main()
{
    int N, a, b;
    cin >> N >> a >> b;
    int res = b - a;
    bool ok = res > 0;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        if (b - a != res) {
            ok = 0;
        }
    }
    cout << (ok ? res : -1) << endl;
    return 0;
}
