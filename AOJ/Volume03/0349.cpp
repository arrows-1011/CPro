#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAX = 100000;

int res;
int num[MAX], visited[MAX];

void dfs(int v, int c, const vector<int>& a)
{
    visited[v] = 0; num[v] = c;
    int to = (v + a[v]) % a.size();
    if (visited[to] == -1) {
        dfs(to, c + 1, a);
    } else if(visited[to] == 0) {
        res += num[v] - num[to] + 1;
    }
    visited[v] = 1;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    memset(num, -1, sizeof(num));
    memset(visited, -1, sizeof(visited));
    
    res = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] == -1) {
            dfs(i, 1, a);
        }
    }
    cout << res << endl;
    return 0;
}
