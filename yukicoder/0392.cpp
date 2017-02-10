#include <iostream>

using namespace std;

void solve(int k, int target, string s)
{
    if (k > target) return;

    if (k == target) {
        cout << s << endl;
        throw 0;
    }
    
    solve(k * 2 + 1, target, s + "L");
    solve(k * 2 + 2, target, s + "R");
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        try {
            solve(0, x, "");
        } catch (...) {}
    }
    return 0;
}
