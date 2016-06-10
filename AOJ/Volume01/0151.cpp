#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300;
 
int n, cnt;
int in[MAX_N][MAX_N];
int s[MAX_N][MAX_N];
 
void cp_in(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            s[i][j] = in[i][j];
        }
    }
}
 
void dfs(int y, int x, bool bit)
{
    if (bit) {
        if (n <= x || n <= y) return;
        cnt++;
        int nx = x + 1;
        int ny = y + 1;
     
        if (0 <= nx && nx < n && 0 <= ny && ny < n && s[ny][nx] == 1) {
            dfs(ny, nx, bit);
        }
    } else {
        if (x < 0 || n <= y) return;
        cnt++;
        int nx = x - 1;
        int ny = y + 1;
         
        if (0 <= nx && nx < n && 0 <= ny && ny < n && s[ny][nx] == 1) {
            dfs(ny, nx, bit);
        }
    }
}
 
int main()
{
    char ch;
    while (cin >> n, n) {
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> ch;
                in[i][j] = ch - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (in[i][j] == 1) {
                    cnt++;
                    a = max(a, cnt);
                } else {
                    cnt = 0;
                }
            }
        }
         
        for (int i = 0; i < n; i++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (in[j][i] == 1) {
                    cnt++;
                    b = max(b, cnt);
                } else {
                    cnt = 0;
                }
            }
        }
 
        cp_in();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt = 0;
                if (s[i][j] == 1) dfs(i, j, 1);
                c = max(c, cnt);
            }
        }
         
        cp_in();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt = 0;
                if (s[i][j] == 1) dfs(i, j, 0);
                d = max(d, cnt);
            }
        }    
        cout << max(max(a, b), max(c, d)) << endl;
    }
    return 0;
}
