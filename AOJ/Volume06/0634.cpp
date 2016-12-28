#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool in_field(int x, int y, int W, int H)
{
    return (0 <= x && x < W && 0 <= y && y < H);
}

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> M(H, vector<int>(W));
    vector<pair<int, int>> a(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> M[i][j];
            a[M[i][j] - 1] = make_pair(j, i);
        }
    }
    
    vector<vector<int>> ridge(H, vector<int>(W, -1));
    constexpr int dx[] = {-1, 0, 1, 0};
    constexpr int dy[] = {0, -1, 0, 1};
    
    int res = 0;
    for (int i = 0; i < H * W; i++) {
        int x, y, large_cnt = 0;
        vector<int> r;
        tie(x, y) = a[i];
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            
            if (!in_field(nx, ny, W, H)) {
                ++large_cnt;
                continue;
            }
            if (ridge[ny][nx] >= 0) {
                r.emplace_back(ridge[ny][nx]);
            }
                
            large_cnt += (M[y][x] < M[ny][nx]);
        }

        constexpr int MUL = 252521;
        
        if (large_cnt == 4) {
            ridge[y][x] = i;
        } else {
            sort(r.begin(), r.end());
            r.erase(unique(r.begin(), r.end()), r.end());
            
            int rs = r.size();
            if (rs == 1) {
                ridge[y][x] = r[0];
            } else {
                ridge[y][x] = MUL;
            }
        }

        if (ridge[y][x] == MUL) {
            ++res;
        }
    }

    cout << res << endl;
    return 0;
}
