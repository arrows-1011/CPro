#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

constexpr double EPS = (1e-8);
#define equals(a, b) (fabs(a - b) < EPS)

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) : x{x}, y{y} {}

    Point operator - (const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }

    bool operator == (const Point& p) const {
        return equals(x, p.x) && equals(y, p.y);
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

    bool operator == (const Segment& seg) const {
        if (s == seg.s && t == seg.t) return 1;
        if (s == seg.t && t == seg.s) return 1;
        return 0;
    }
};

bool parallel(const Segment& s1, const Segment& s2)
{
    Vector a = s1.t - s1.s;
    Vector b = s2.t - s2.s;    
    return equals(cross(a, b), 0);
}

using ll = long long;
constexpr int MAX = 10;

bool con[MAX][MAX];

inline int mod_pow(ll x, int n, int mod)
{
    if (n == 0) return 1;
    int res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}

int I[1 << MAX], bn[1 << MAX];

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

int paint_color_number(int n)
{
    vector<int> N(1 << n);
    for (int i = 0; i < n; i++) {
        int bit = (1 << i);
        for (int j = 0; j < n; j++) {
            if (con[i][j]) {
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

using Polygon = vector<Point>;
#define curr(G, i) (G[i % G.size()])
#define next(G, i) (G[(i + 1) % G.size()])

bool contain(const Segment& s, const Point& p)
{
    if (s.s == p) return 0;
    if (s.t == p) return 0;
    return ccw(s.s, s.t, p) == 0;
}

bool check(const Polygon& p1, const Polygon& p2)
{
    int N = p1.size(), M = p2.size();    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            const Segment s1{curr(p1, i), next(p1, i)};
            const Segment s2{curr(p2, j), next(p2, j)};
            if (s1 == s2) return 1;
            if (!parallel(s1, s2)) continue;
            if (contain(s1, s2.s) || contain(s1, s2.t) ||
                contain(s2, s1.s) || contain(s2, s1.t)) return 1;
        }
    }
    return 0;
}

bool run()
{
    int N;
    cin >> N;
    if (N == 0) {
        return false;
    }
    
    map<string, int> num;
    vector<int> c(N);
    vector<Polygon> pgs(N);
    
    int idx = 0;
    string country;
    for (int i = 0; i < N; i++) {
        cin >> country;
        
        if (num.count(country) == 0) {
            num[country] = idx++;
        }
        
        c[i] = num[country];
        
        double x, y;
        Polygon pg;
        while (cin >> x, x != -1) {
            cin >> y;
            pg.emplace_back(x, y);
        }
        pgs[i] = pg;
    }
    
    memset(con, 0, sizeof(con));

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (c[i] == c[j]) continue;
            if (check(pgs[i], pgs[j])) {
                con[c[i]][c[j]] = con[c[j]][c[i]] = 1;
            }
        }
    }
    cout << paint_color_number(idx) << endl;
    return true;
}

int main()
{
    while (run())
        ;
    return 0;
}
