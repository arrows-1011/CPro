#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr double EPS = (1e-10);

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) : x{x}, y{y} {}

    Point operator - (const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }
};

double dot(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(const Point& a, const Point& b)
{
    return a.x * b.y - b.x * a.y;
}

double norm(const Point& p)
{
    return dot(p, p);
}

constexpr int COUNTER_CLOCKWISE = +1;
constexpr int CLOCKWISE         = -1;
constexpr int ONLINE_BACK       = +2;
constexpr int ONLINE_FRONT      = -2;
constexpr int ON_SEGMENT        = +0;
using Vector = Point;

int ccw(const Point& p0, const Point& p1, const Point& p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)  return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS)   return ONLINE_BACK;
    if (norm(a) < norm(b))  return ONLINE_FRONT; 
    return ON_SEGMENT;                        
}

struct Segment {
    Point s, t;
    Segment() {}
    Segment(Point s, Point t) : s{s}, t{t} {}
};

bool intersect(const Segment& a, const Segment& b)
{
    Point s[2]{a.s, a.t}, t[2]{b.s, b.t};
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
            ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}

bool intersect(const vector<Point>& a, const vector<Point>& b)
{
    int as = a.size(), bs = b.size();
    for (int i = 0; i < as - 1; i++) {
        for (int j = 0; j < bs - 1; j++) {
            Segment s1{a[i], a[i + 1]}, s2{b[j], b[j + 1]};
            if (intersect(s1, s2)) {
                return 1;
            }
        }
    }
    return 0;
}

constexpr int MAX = 55; 

bool con[MAX][MAX];

void init(int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            con[i][j] = 1;
        }
    }
}

using ll = long long;

inline int mod_pow(ll x, int n, int mod)
{
    if (n == 0) return 1;
    int res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}

int I[1 << 22], bn[1 << 22];

bool c(int n, int k)
{
    ll g = 0;
    constexpr int MOD = 10009;    
    for (int i = 0; i < (1 << n); i++) {
        if (bn[i] % 2 == 0) {
            g += mod_pow(I[i], k, MOD);
        } else {
            g -= mod_pow(I[i], k, MOD);
        }
    }
    return (g % MOD + MOD) % MOD != 0;
}

int paint_color_num(int n)
{
    vector<int> N(1 << n);
    for (int i = 0; i < n; i++) {
        int bit = (1 << i);
        for (int j = 0; j < n; j++) {
            if (i != j && con[i][j]) {
                bit |= (1 << j);
            }
        }
        N[i] = bit;
    }
        
    memset(I, 0, sizeof(I));
    I[0] = 1;
    for (int S = 1; S < (1 << n); S++) {
        bn[S] = __builtin_popcount(S);
        int v = 0;
        while (!(S >> v & 1)) v++;
        I[S] = I[S - (1 << v)] + I[S & ~N[v]];
    }
            
    int L = 0, R = n;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (c(n, mid)) {
            R = mid;
        } else {
            L = mid;
        }           
    }
    return R;
}

int main()
{
    int N;
    while (cin >> N, N) {
        vector<vector<Point>> ps(N);
        for (int i = 0; i < N; i++) {
            int S;
            cin >> S;
            ps[i].resize(S);
            for (int j = 0; j < S; j++) {
                cin >> ps[i][j].x >> ps[i][j].y;
            }
        }
        
        init(N);
                
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (!intersect(ps[i], ps[j])) {
                    con[i][j] = con[j][i] = 0;
                }
            }
        }
        cout << paint_color_num(N) << endl;
    }        
    return 0;
}
