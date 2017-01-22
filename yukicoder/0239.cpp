#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<string>> s(N, vector<string>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> s[i][j];
        }
    }
    
    vector<int> res;
    for (int j = 0; j < N; j++) {
        bool ok = 1;
        for (int i = 0; i < N; i++) {
            if (i == j) continue;
            if (s[i][j] != "nyanpass") {
                ok = 0;
                break;
            }
        }
        if (ok) res.emplace_back(j + 1);
    }
    
    if (res.size() != 1) {
        cout << -1 << endl;
    } else {
        cout << res[0] << endl;
    }
    return 0;
}
