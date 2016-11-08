/*
  8puzzleを解く
  ただしLIMITは30~35
*/

#include <iostream>
#include <vector>

using namespace std;
 
constexpr int INF = (1 << 29);
using ll = long long;
 
struct P {
    int x, y;
    P(int x, int y) : x{x}, y{y} {}
};
 
ll getValue(vector<int>& v)
{
    ll res = 0LL;
    for (auto x : v) {
	res *= 10LL;
	res += x;
    }
    return res;
}
 
vector<int> getState(ll x)
{
    vector<int> res;
    while (x > 0LL) { 
	res.push_back(x%10LL);
	x /= 10LL;
    }
    if (res.size() == 8) res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
}
 
P getPos(int x)
{
    x--;
    return {x % 3, x / 3};
}
 
int getMD(ll x)
{
    vector<int> v = getState(x);
    int res = 0;
    for (int i = 0; i < 9; i++) {
	if (v[i] == 0) continue;
	P tp = getPos(v[i]);
	res += abs(i % 3 - tp.x) + abs(i / 3 - tp.y);
    }
    return res;
}
 
int LIMIT;
constexpr int dx[] = {-1, +0, +1, +0};
constexpr int dy[] = {+0, -1, +0, +1};

bool in_field(int x, int y)
{
    return (0 <= x && x < 3 && 0 <= y && y < 3);
}
 
bool solve(int sp, ll st, int step, int prev)
{
    int md = getMD(st);
    if (md == 0) return true;
    if (md + step > LIMIT) {
	return false;
    }
    int x = sp % 3, y = sp / 3;
    for (int i = 0; i < 4; i++) { 
	int nx = x + dx[i], ny = y + dy[i];
	if (abs(i - prev) == 2) continue;
	if (!in_field(nx, ny)) continue;
	vector<int> v = getState(st);
	int nsp = ny * 3 + nx;
	swap(v[sp], v[nsp]);
	if (solve(nsp, getValue(v), step + 1, i)) {
	    return true;
	}
    }
    return false;
}
 
int main()
{
    int sp = -1;
    vector<int> v(9);
    for (int i = 0; i < 9; i++) {
	cin >> v[i];
	if (v[i] == 0) sp = i;
    }
    ll st = getValue(v);
    for (LIMIT = 0; LIMIT < 35; LIMIT++) {
	if (solve(sp, st, 0, INF)) {
	    cout << LIMIT << endl;
	    break;
	}
    }
    return 0;
}
