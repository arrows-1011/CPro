#include <bits/stdc++.h>

using namespace std;

typedef vector<char> Vec;
typedef vector<Vec> Mat;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

Mat B;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < 10 && 0 <= ny && ny < 10 &&
            B[ny][nx] == 'o') {
            B[ny][nx] = 'x';
            dfs(nx, ny);
        }
    } 
}

bool check()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (B[i][j] == 'o') return 0;
        }
    }
    return 1;
}

int main()
{
    Mat A(10, Vec(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A[i][j];
        }
    }
    
    bool found = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (A[i][j] == 'x') {
                B = A;
                dfs(j, i);
                if (check()) {
                    found = 1;
                }
            }
        }
    }
    cout << (found ? "YES" : "NO") << endl;
    return 0;
}
