#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define MIN first
#define MAX second
constexpr int MAX_S = 252;
constexpr int INF = (1 << 29);

string S;
pair<int, int> mem[MAX_S][MAX_S];

void init(int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mem[i][j] = {+INF, -INF};
        }
    }
}

void update_max(int& l, int r)
{   
    if (l < r) l = r;
}

void update_min(int& l, int r)
{
    if (l > r) l = r;
}

// 区間のpair(MIN, MAX)
pair<int, int> rec(int L, int R)
{
    pair<int, int>& res = mem[L][R];
    if (res != make_pair(+INF, -INF)) {
        return res;
    }

    if (R - L == 0) {
        int v = S[L] - '0';
        return (res = make_pair(v, v));
    }    

    if (S[L] == '(' && R - L > 2) {
        auto r = rec(L + 1, R);
        update_min(res.MIN, r.MIN);
        update_max(res.MAX, r.MAX);
        return res;
    }

    if (S[R] == ')' && R - L > 2) {
        auto r = rec(L, R - 1);
        update_min(res.MIN, r.MIN);
        update_max(res.MAX, r.MAX);
        return res;
    }
    
    for (int i = L + 1; i <= R - 1; i++) {
        char c = S[i];   
        if (c != '+' && c != '-') continue;                 
        
        auto res_l = rec(L, i - 1); // Left
        auto res_r = rec(i + 1, R); // Right

        if (c == '+') {            
            update_min(res.MIN, res_l.MIN + res_r.MIN);
            update_max(res.MAX, res_l.MAX + res_r.MAX);            
        }
        if (c == '-') {           
            update_min(res.MIN, res_l.MIN - res_r.MAX);
            update_max(res.MAX, res_l.MAX - res_r.MIN);
        }
    } 
    return res;
}

void solve()
{
    int N = S.size();
    init(N);
    cout << rec(0, N - 1).MAX << endl;    
}

int main()
{
    cin >> S;
    solve();    
    return 0;
}
