#include <iostream>

using namespace std;

int main()
{
    int N, C, M;
    cin >> N >> C >> M;
    bool poss = 1;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (C * M < p) {
            poss = 0;
        }
    }
    cout << (poss ? "Yes" : "No") << endl;
    return 0;
}
