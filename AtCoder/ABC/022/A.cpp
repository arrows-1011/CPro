#include <iostream>

using namespace std;

bool between(int l, int r, int x)
{
    return (l <= x && x <= r);
}

int main()
{
    int N, S, T, W, A, day = 0;
    cin >> N >> S >> T >> W;
    if (between(S, T, W)) {
        ++day;
    }
    for (int i = 0; i < N-1; i++) {
        cin >> A;
        W += A;
        if (between(S, T, W)) {
            ++day;
        }
    }
    cout << day << endl;
    return 0;
}
