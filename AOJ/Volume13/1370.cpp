#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ull = unsigned long long;
constexpr int MAX = 4000;
constexpr ull B = 100000007ULL;

vector<vector<int>> make(const string& str)
{
    int N = str.size();
    vector<vector<int>> cnt(N + 1, vector<int>(26));
    for (int i = 0; i < N; i++) {
        cnt[i + 1][str[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            cnt[i + 1][j] += cnt[i][j];
        }  
    }
    return cnt;
}

ull get_hash(int len, int s,
             const vector<vector<int>>& cnt)
{
    auto l = cnt[s];
    auto r = cnt[s + len];
    
    ull res = 1;
    for (int i = 0; i < 26; i++) {
        res = res * B + (r[i] - l[i]);
    }
    return res;
}

int main()
{
    string S, T;
    cin >> S >> T;
    
    if (S.size() < T.size()) swap(S, T);

    int s = S.size(), t = T.size();
    
    auto sc = make(S);
    auto tc = make(T);
    
    vector<ull> vec[MAX + 1];
    for (int i = s; i >= 1; i--) {
        for (int j = 0; j <= s - i; j++) {
            vec[i].emplace_back(get_hash(i, j, sc));
        }
        sort(vec[i].begin(), vec[i].end());
        vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
    }    
    
    int res = 0;
    for (int i = t; i >= 1; i--) {
        for (int j = 0; j <= t - i; j++) {
            if (binary_search(vec[i].begin(), vec[i].end(), get_hash(i, j, tc))) {
                res = max(res, i);
            }
        }
    }
    cout << res << endl;
    return 0;
}
