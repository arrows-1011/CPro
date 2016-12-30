#include <iostream>
#include <vector>

using namespace std;
 
struct P {
    int x, y;
    P(int x, int y) : x{x}, y{y} {}
};
 
int limit;
vector<int> v;

constexpr int X[] = {2, 1, 2, 3, 0, 1, 2, 3, 4, 1, 2, 3, 2};
constexpr int Y[] = {0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4};
 
int next_pos(int x, int y)
{
    for (int i = 0; i < 13; i++) {
        if (x == X[i] && y == Y[i]) {
            return i;
        }
    }        
    return -1;
}
 
int getMD()
{
    int sum = 0;
    for (int i = 0; i < 13; i++) {
        if (v[i] == 0) continue;
        sum += abs(X[i] - X[v[i]]) + abs(Y[i] - Y[v[i]]);
    }
    return sum;
}
 
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, -1, 0, 1};
 
bool dfs(const int* sp, int step)
{
    int md = getMD();
    if (md == 0) return 1;
    if (md + step > limit) {
        return 0;
    }
    
    for (int i = 0; i < 2; i++) {
        int x = X[sp[i]], y = Y[sp[i]];
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            int next = next_pos(nx, ny);
            if (next == -1) continue;
            
            const int nsp1[] = {next, sp[1]}, nsp2[] = {sp[0], next};
            
            swap(v[sp[i]], v[next]);
            if (i == 0 && dfs(nsp1, step + 1)) {
                return 1;
            }
            if (i == 1 && dfs(nsp2, step + 1)) {
                return 1;
            }
            swap(v[sp[i]], v[next]);
        }
    }
    return 0;
}
 
int main()
{
    int x;
    while (cin >> x, x != -1) {
        int sp[2];
        v.resize(13); v[0] = x;
        for (int i = 1; i < 13; i++) {
            cin >> v[i];
        }

        for (int i = 0, j = 0; i < 13; i++) {
            if (v[i] == 0) {
                sp[j++] = i;
            }
        }

        bool found = 0;
        constexpr int LIMIT = 20;
        for (limit = 0; limit <= LIMIT; limit++) {
            if (dfs(sp, 0)) {
                cout << limit << endl;
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "NA" << endl;
        }
    }
    return 0;
}
