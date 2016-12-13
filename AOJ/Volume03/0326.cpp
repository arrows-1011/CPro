#include <iostream>
#include <map>
#include <vector>

using namespace std;

using P = pair<string, string>;

int main()
{
    int N, F, M, cnt = 0;
    map<P, int> comb;
    cin >> N >> F;
    for (int i = 0; i < N; i++) {
        cin >> M;
        vector<string> v(M);
        for (int j = 0; j < M; j++) {
            cin >> v[j];
        }
        for (int j = 0; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                string a = v[j];
                string b = v[k];
                if (a > b) swap(a, b);
                comb[P(a, b)]++;
            }
        }
    }
    for (auto& it : comb) {
        if (it.second >= F) ++cnt;
    }    
    cout << cnt << endl;
    for (auto& it : comb) {
        if (it.second >= F) {
            cout << it.first.first << " " << it.first.second << endl;
        }
    }
    return 0;
}
