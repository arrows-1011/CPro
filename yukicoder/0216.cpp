#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> p(114);
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        p[b] += a[i];
    }

    int point = p[0];
    bool win = 1;
    for (int i = 1; i < 114; i++) {
        if (point < p[i]) {
            win = 0;
            break;
        }
    }
    cout << (win ? "YES" : "NO") << endl;
    return 0;
}
