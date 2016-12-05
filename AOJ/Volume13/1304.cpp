#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

constexpr int dx[] = {-1, -1, -1, +0, +0, +1, +1, +1};
constexpr int dy[] = {-1, +0, +1, -1, +1, -1, +0, +1};

bool is_goal(const vector<string>& f)
{
    int N = f.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (f[i][j] == '#') {
                return 0;
            }
        }
    }
    return 1;
}

bool in_field(int x, int y, int N)
{
    return (0 <= x && x < N && 0 <= y && y < N);
}

vector<string> next(int x, int y, const vector<string>& f)
{
    int N = f.size();
    vector<string> nf = f;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {            
            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int nx = j + dx[k], ny = i + dy[k];
                if (!in_field(nx, ny, N)) continue;
                if (f[ny][nx] == '#' || (nx == x && ny == y)) {
                    cnt++;
                }
            }

            if (f[i][j] == '#') {
                nf[i][j] = ((cnt == 2 || cnt == 3) ? '#' : '.');
            } else {
                nf[i][j] = (j == x && i == y ? '@' : (cnt == 3 ? '#' : '.'));
            }
        }
    } 
    return nf;
}

int bfs(int sx, int sy, const vector<string>& sf)
{
    int N = sf.size();
    
    queue<tuple<int, int, vector<string>>> Q;
    queue<int> Qt;
    
    Q.push(make_tuple(sx, sy, sf));
    Qt.push(0);    

    set<vector<string>> closed;
    
    int x, y;
    vector<string> f;
    
    while (!Q.empty()) {
        tie(x, y, f) = Q.front(); Q.pop();
        int t = Qt.front(); Qt.pop();
        
        if (is_goal(f)) return t;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!in_field(nx, ny, N)) continue;
            if (f[ny][nx] == '#') continue;            
            
            auto nf = next(nx, ny, f);
            if (closed.count(nf) == 0) {
                closed.insert(nf);
                Q.push(make_tuple(nx, ny, nf));
                Qt.push(t + 1);
            }
        }
    }        
    return -1;
}

int main()
{
    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;
        vector<string> f(N);
        int sx, sy;
        for (int i = 0; i < N; i++) {
            cin >> f[i];
            for (int j = 0; j < N; j++) {
                if (f[i][j] == '@') {
                    sx = j; sy = i;
                }
            }
        }
        cout << bfs(sx, sy, f) << endl;
    }        
    return 0;
}

