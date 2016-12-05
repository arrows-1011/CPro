#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x{x}, y{y} {}

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
};

struct Circle : Point {
    double r;
    Circle() {}
    Circle(double x, double y, double r) : Point(x, y), r{r} {}
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

double abs(const Point& p)
{
    return sqrt(norm(p));
}

int mem[1145];

bool contain(const Point& p, const Circle& c)
{  
    return (sqrt(pow(p.x - c.x, 2) + pow(p.y - c.y, 2)) < c.r);
}

bool intersect(const Circle& a, const Circle& b)
{
    double d = abs(a - b);
    return (d <= a.r + b.r && d >= abs(a.r - b.r));
}

int solve(int v, const vector<int>& n, const vector<Circle>& c)
{
    int& res = mem[v];
    if (res != -1) return res;
    res = 0;
    for (int i = 0; i < (int)n.size(); i++) {
        if (n[i] == v) continue;
        if (!intersect(c[v], c[n[i]]) && c[v].r > c[n[i]].r) {
            res = max(res, solve(n[i], n, c) + 1);
        }
    }    
    return res;
}

int main()
{
    int N;
    while (cin >> N, N > 0) {
        Point s, t;     
        cin >> s.x >> s.y >> t.x >> t.y;
        vector<int> n[2];
        vector<Circle> c(N + 2);
        for (int i = 0; i < N; i++) {
            cin >> c[i].x >> c[i].y >> c[i].r;
            bool in[] = {contain(s, c[i]), contain(t, c[i])};
            if (in[0] + in[1] == 1) {
                for (int j = 0; j < 2; j++) {
                    if (in[j]) n[j].emplace_back(i);
                }
            }
        }

        n[0].emplace_back(N);
        n[1].emplace_back(N + 1);
        c[N] = Circle(s.x, s.y, 0);
        c[N + 1] = Circle(t.x, t.y, 0);

        memset(mem, -1, sizeof(mem));
        
        int res = 0;
        for (auto& i : n[0]) {
            for (auto& j : n[1]) {
                if (intersect(c[i], c[j])) continue;
                res = max(res, solve(i, n[0], c) + solve(j, n[1], c));
            }
        }
        cout << res << endl;
    }        
    return 0;
}
