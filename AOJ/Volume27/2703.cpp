#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 15
#define MAX 2200
#define OFFSET 1100
typedef pair<int, int> pii;
 
class Dice {
  private:
    void roll(int a, int b, int c, int d)
    {
        swap(v[a], v[b]);
        swap(v[b], v[d]);
        swap(v[c], v[d]);
    }
     
  public:
    int v[6], x, y;
    string order;
    void roll_B() { roll(0, 1, 4, 5); }
    void roll_R() { roll(0, 3, 2, 5); }
    void roll_F() { roll(0, 4, 1, 5); }
    void roll_L() { roll(0, 2, 3, 5); }
};
 
int bit[MAX][MAX];
 
void rot(int x, Dice &d)
{
    bit[d.y][d.x] |= (1<<x);
    for (auto &c: d.order) {
        if (c == 'L') {
            c = 'R';
            d.roll_L();
            d.x--;
        } else if (c == 'F') {
            c = 'B';
            d.roll_F();
            d.y--;
        } else if (c == 'R') {
            c = 'L';
            d.roll_R();
            d.x++;
        } else {
            c = 'F';
            d.roll_B();
            d.y++;
        }
        bit[d.y][d.x] |= (1<<x);
    }
    reverse(d.order.begin(), d.order.end());
}
 
int get_cost(int S, Dice d)
{
    int res = 0;
    set<pii> used;
    if ((bit[d.y][d.x] & S) == 0) {
        used.insert(pii(d.y, d.x));
        res += d.v[5];
    }
         
    for (auto c: d.order) {
        if (c == 'L') {
            d.x--;
            d.roll_L();
        } else if (c == 'F') {
            d.y--;
            d.roll_F();
        } else if (c == 'R') {
            d.x++;
            d.roll_R();
        } else {
            d.y++;
            d.roll_B();
        }
         
        if (used.count(pii(d.y, d.x)) == 0 && (bit[d.y][d.x] & S) == 0) {
            used.insert(pii(d.y, d.x));
            res += d.v[5];
        }
    }
    return res;
}
 
int main()
{
    int N;
    while (cin >> N, N) {
        vector<Dice> d(N);
        for (int i = 0; i < N; i++) {
            cin >> d[i].x >> d[i].y;
            d[i].x += OFFSET; d[i].y += OFFSET;
            cin >> d[i].v[3] >> d[i].v[2] >> d[i].v[1];
            cin >> d[i].v[4] >> d[i].v[5] >> d[i].v[0];
            cin >> d[i].order;
        }
 
        memset(bit, 0, sizeof(bit));
         
        for (int i = 0; i < N; i++) {
            rot(i, d[i]);
        }        
         
        int dp[1<<MAX_N];
        memset(dp, -1, sizeof(dp));
 
        dp[0] = 0;
        for (int i = 0; i < (1<<N); i++) {
            if (dp[i] == -1) continue;                        
            for (int j = 0; j < N; j++) {
                if (i >> j & 1) continue;
                int ni = i | (1<<j);                
                dp[ni] = max(dp[ni], dp[i] + get_cost(i, d[j]));
            }
        }
        cout << dp[(1<<N)-1] << endl;
    }
    return 0;
}
