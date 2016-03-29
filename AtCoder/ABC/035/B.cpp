#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
map<char, int> dir =
{
    {'L', 0},
    {'U', 1},
    {'R', 2},
    {'D', 3},
    {'?', 4}
};

int get_manhattan_distance(int x, int y)
{
    return abs(x) + abs(y);
}

int move(int &x, int &y, string &S)
{
    int cnt = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (dir[S[i]] <= 3) {
            x += dx[dir[S[i]]];
            y += dy[dir[S[i]]];
        } else {
            ++cnt;
        }
    }
    return cnt;
}

int min_dist(int x, int y, int h)
{
    for (int i = 0; i < h; i++) {
        int min = INF, k = -1;
        for (int j = 0; j < 4; j++) {
            int d = get_manhattan_distance(x + dx[j], y + dy[j]);
            if (d < min) {
                min = d;
                k = j;
            }
        }
        x += dx[k];
        y += dy[k];
    }
    return get_manhattan_distance(x, y);
}

int max_dist(int x, int y, int h)
{
    for (int i = 0; i < h; i++) {
        int max = -INF, k = -1;
        for (int j = 0; j < 4; j++) {
            int d = get_manhattan_distance(x + dx[j], y + dy[j]);
            if (d > max) {
                max = d;
                k = j;
            }
        }
        x += dx[k];
        y += dy[k];
    }
    return get_manhattan_distance(x, y);
}

int main()
{
    string S;
    int T, x = 0, y = 0;
    cin >> S >> T;
    int h = move(x, y, S);
    cout << (T == 1 ? max_dist(x, y, h) : min_dist(x, y, h)) << endl;
    return 0;
}
