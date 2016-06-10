#include <bits/stdc++.h>

using namespace std;
 
#define RIGHT '>'
#define LEFT '<'
#define TOP '^'
#define UNDER 'v'
#define LOOP 'l'
#define END '.'
#define MAX 101
 
void dfs(char mp[MAX][MAX], int i, int j)
{
    if (mp[i][j] == END) {
        printf("%d %d\n", j, i);
        return;
    }
    if (mp[i][j] == LOOP) {
        printf("LOOP\n");
        return;
    }
     
    if (mp[i][j] == RIGHT) {
        mp[i][j] = LOOP;
        dfs(mp, i, j+1);
    } else if (mp[i][j] == LEFT) {
        mp[i][j] = LOOP;
        dfs(mp, i, j-1);
    } else if (mp[i][j] == TOP) {
        mp[i][j] = LOOP;
        dfs(mp, i-1, j);
    } else {
        mp[i][j] = LOOP;
        dfs(mp, i+1, j);
    }
}
 
int main()
{
    char mp[MAX][MAX];
    int n, m;
     
    while (cin >> n >> m, (n | m)) {
        for (int i = 0; i < n; i++) {
            cin >> mp[i];
        }
        dfs(mp, 0, 0);
    }
    return 0;
}
