#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> diff(const vector<int>& a, const vector<int>& b)
{
    vector<int> res(10);
    for (int i = 1; i <= 9; i++) {
        res[i] = a[i] - b[i];
    }
    return res;
}

bool check_diff(const vector<int>& a, const vector<int>& b)
{
    for (int i = 1; i <= 9; i++) {
        if (a[i] < b[i]) return 0;
    }
    return 1;
}

using ull = unsigned long long;

class Hash {
  public:
    size_t operator () (const vector<int>& v) const
    {
        const ull B = 100000007;
        ull r = 0;
        for (const auto& n : v) {
            r = r * B + n;
        }
        return r;
    }
};

unordered_map<vector<int>, int, Hash> mem;
vector<vector<int>> pat;

bool check(const vector<int>& p)
{
    int res = 0, cnt = 0;
    for (int i = 1; i <= 9; i++) {
        cnt += p[i];
        res += p[i] * i;
    }
    return (res == 10 && cnt > 2);
}

void make_pattern(int n, const vector<int>& p)
{
    if (n == 10) {
        if (check(p)) {
            pat.emplace_back(p);
        }
        return;
    }
    for (int i = 0; i <= 10 / n; i++) {
        vector<int> np = p;
        np[n] += i;
        make_pattern(n + 1, np);
    }
}

int solve(const vector<int>& m_cnt)
{
    int res = 0;
    if (mem.count(m_cnt) != 0) {
        return mem[m_cnt];
    }

    for (const auto& p : pat) {
        if (check_diff(m_cnt, p)) {
            res = max(res, solve(diff(m_cnt, p)) + 1);
        }
    }
    return mem[m_cnt] = res;
}

int main()
{
    int N;
    make_pattern(1, vector<int>(10));
    while (cin >> N, N > 0) {
        vector<int> m_cnt(10);
        for (int i = 0; i < N; i++) {
            int m;
            cin >> m;
            m_cnt[m]++;
        }

        int res = 0;
        for (int i = 1; i <= 5; i++) {
            int mini = min(m_cnt[i], m_cnt[10 - i]); 
            if (i == 5) mini /= 2;
            res += mini;
            m_cnt[i] -= mini;
            m_cnt[10 - i] -= mini;
        }
        mem.clear();
        res += solve(m_cnt);
        cout << res << endl;
    }        
    return 0;
}
