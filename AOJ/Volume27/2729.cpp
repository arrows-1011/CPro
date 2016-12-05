#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<char> D(N);
    vector<int> L(N);
    vector<pair<int, int>> p;
    for (int i = 0; i < N; i++) {
        cin >> D[i] >> L[i];
        if (D[i] == 'y') {
            p.emplace_back(L[i], i);
        }        
    }
    
    sort(p.begin(), p.end());
    
    int res = 0;
    vector<bool> rem(N);
    for (const auto c : p) {
        int i = c.second;
        if (rem[i]) continue;
        rem[i] = 1;
        ++res;
        for (int j = i + 1; j < N; j++) {
            if (D[j] == 'y') {
                rem[j] = 1;
            } else if (L[i] <= L[j]) {
                break;
            }
        }
        for (int j = i - 1; j >= 0; j--) {
            if (D[j] == 'y') {
                rem[j] = 1;
            } else if (L[i] <= L[j]) {
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
