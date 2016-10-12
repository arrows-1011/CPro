#include <bits/stdc++.h>

using namespace std;

#define MAX 100
#define EPS (1e-10)

struct Point {
    double x, y;

    Point () {}
    Point (double x, double y) : x{x}, y{y} {}
};

Point operator - (const Point &a, const Point &b)
{
    return Point(a.x - b.x, a.y - b.y);
}

double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b)
{
    return a.x * b.y - b.x * a.y;
}

double norm(const Point &p)
{
    return dot(p, p);
}

int par[MAX], rnk[MAX];

void init(int n)
{
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) {
            rnk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return (find(x) == find(y));
}

#define COUNTER_CLOCKWISE +1
#define CLOCKWISE         -1
#define ONLINE_BACK       +2
#define ONLINE_FRONT      -2
#define ON_SEGMENT        +0
typedef Point Vector;

int ccw(const Point &p0, const Point &p1, const Point &p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)  return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS)   return ONLINE_BACK; 
    if (norm(a) < norm(b))  return ONLINE_FRONT;
    return ON_SEGMENT;
}

int contain(const vector<Point> &q, const Point &p)
{
    bool in = false;
    for (int i = 0; i < 4; i++) {
        Point a = q[i] - p, b = q[(i + 1) % 4] - p;
        if (a.y > b.y) swap(a, b);
        if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
    }
    return (in ? 2 : 0); 
}

bool intersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    Point s[2] = {a, b}, t[2] = {c, d};
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
	    ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}

int main()
{
    int N;
    while (cin >> N, N) {
        for (int n = 0; n < N; n++) {
            int M;
            cin >> M;
            vector<vector<Point>> quad(M, vector<Point>(4));
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < 4; j++) {
                    cin >> quad[i][j].x >> quad[i][j].y;
                }
            }

            init(M);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    if (i == j) continue;
                    
                    bool connect = 0;
                    for (int k = 0; k < 4; k++) {
                        if (contain(quad[i], quad[j][k]) != 0) {
                            connect = 1;
                            break;
                        }

                        for (int l = 0; l < 4; l++) {
                            if (intersect(quad[i][l], quad[i][(l + 1) % 4],
                                          quad[j][k], quad[j][(k + 1) % 4])) {
                                connect = 1;
                                break;
                            }
                        }
                        if (connect) break;
                    }
                    if (connect) {
                        unite(i, j);
                    }
                }
            }
            
            int res = 0;
            vector<bool> used(M);
            for (int i = 0; i < M; i++) {
                int x = find(i);
                if (!used[x]) {
                    used[x] = 1;
                    res++;
                }
            }
            cout << res << endl;
        }
    }        
    return 0;
}
