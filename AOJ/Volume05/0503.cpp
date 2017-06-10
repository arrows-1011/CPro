#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void move_cup(vector<vector<int>> &v,
              int from,
              int to)
{
    int p = v[from].back();
    v[from].pop_back();
    v[to].emplace_back(p);
}

void next_state(int &prev,
                int &curr,
                vector<vector<int>> &curr_cup)
{
    for (int i = 0; i < 3; i++) {
        int size = curr_cup[i].size();
        if (size == 0) {
            continue;
        }

        for (int di : {-1, 1}) {
            int next = i + di;
            if (next < 0 || next >= 3 || (curr == i && prev == next)) {
                continue;
            }

            int nsize = curr_cup[next].size();
            if (nsize == 0 ||
                curr_cup[i].back() > curr_cup[next].back()) {
                move_cup(curr_cup, i, next);
                prev = i; curr = next;
                return;
            }    
        }
    }
}

int solve(vector<vector<int>> curr_cup,
          const vector<vector<int>> &target)
{
    int res = 0;
    int prev = -1, curr = 0;
    while (curr_cup != target) {
        next_state(prev, curr, curr_cup);
        res++;
    }
    return res;
}

int main()
{
    int N, M;
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        
        vector<vector<int>> target(3);
        for (int i = 0; i < 3; i++) {
            int K;
            cin >> K;
            for (int j = 0; j < K; j++) {
                int x;
                cin >> x;
                target[i].emplace_back(--x);
            }
        }

        vector<vector<int>> curr_cup(3, vector<int>(0));
        for (int i = 0; i < N; i++) {
            curr_cup[0].emplace_back(i);
        }      

        int res = solve(curr_cup, target);
        swap(target[0], target[2]);
        res = min(res, solve(curr_cup, target));

        if (res <= M) {
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
