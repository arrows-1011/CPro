#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Mat;

Mat a(5, Vec(5));
int score[5];

const int dx[] = {-1, +0, +1, +0};
const int dy[] = {+0, -1, +0, +1};

bool inField(int x, int y)
{
    return (0 <= x && x < 5 && 0 <= y && y < 5);
}

int erase(Mat &m)
{
    bool e[5][5] = {{}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {                        
            if (m[i][j] == 0) {
                continue;
            }
            int cnt[2] = {1, 1};
            for (int k = 0; k < 4; k++) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                while (inField(ni, nj) &&
                       m[i][j] == m[ni][nj]) {
                    ni += dy[k];
                    nj += dx[k];
                    ++cnt[k&1];
                }
            }
            if (cnt[0] >= 3 || cnt[1] >= 3) {
                e[i][j] = 1;
            }
        }
    }
    int point = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (e[i][j]) {
                point += score[m[i][j]-1];
                m[i][j] = 0;
            }
        }
    }
    return point;
}

void fall(Mat &m)
{
    for (int j = 0; j < 5; j++) {
        for (int i = 4; i >= 1; i--) {
            if (m[i][j] == 0) {                
                for (int k = i-1; k >= 0; k--) {
                    if (m[k][j] != 0) {
                        swap(m[i][j], m[k][j]);
                        break;
                    }
                }
            }
        }
    }
}

int get_point()
{
    Mat b = a;
    int point = 0, bp = 1;
    bool update = 1;
    
    while (update) {
        update = 0;        
        Mat nb = b;
        point += erase(nb) * bp++;
        fall(nb);
        if (nb != b) {        
            update = 1;
            b = nb;
        }
    }
    return point;
}

int dfs(int y, int x, int n, int p)    
{
    int point = get_point();
    if (n > 0) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inField(nx, ny) && (p == -1 || (p + 2) % 4 != i)) {
                swap(a[ny][nx], a[y][x]);
                point = max(point, dfs(ny, nx, n-1, i));
                swap(a[ny][nx], a[y][x]);
            }        
        }
    }
    return point;
}

int main()
{
    int n;
    while (cin >> n, n != -1) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
    
        for (int i = 0; i < 5; i++) {
            cin >> score[i];
        }

        int max_point = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                max_point = max(max_point, dfs(i, j, n, -1));
            }
        }   
        cout << max_point << endl;
    }
    return 0;
}
