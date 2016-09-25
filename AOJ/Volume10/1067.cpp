#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-8)
#define INF 101010

struct Point {
    double x, y;
    
    Point () {}
    Point (double x, double y) : x(x), y(y) {}

    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

double cross(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

int ccw(const Point &p0, const Point &p1, const Point &p2)
{
    Point a = p1 - p0, b = p2 - p0;
    if (cross(a, b) > EPS)  return -1; // COUNTER CLOCK WISE
    return +0;
}

#define next(G,i) (G[(i+1)%G.size()])

double get_area(double l, double r, int W)
{
    vector<Point> pg(4);
    pg[0] = Point(0, 0);
    pg[1] = Point(W, 0);
    pg[2] = Point(W, r);
    pg[3] = Point(0, l);
    
    double res = 0;
    for (int i = 0; i < (int)pg.size(); i++) {
	res += cross(pg[i], next(pg, i));
    }
    return abs(res)/2.0;
}


int main()
{
    int N, M, W, H, S;
    while (cin >> N >> M >> W >> H >> S, N) {
        vector<double> l(M+1), r(M+1);
        l[0] = r[0] = 0;
        
        vector<int> s(M+1, 0);
        for (int i = 1; i <= M; i++) {
            scanf("%lf %lf", &l[i], &r[i]);
            s[i] = get_area(l[i], r[i], W);
        }        

        vector<int> choco(M+1, 0);
        
        Point p;
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &p.x, &p.y);
            int lb = 0, ub = M+1;
            while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                if (ccw(Point(0, l[mid]), Point(W, r[mid]), p) == -1) {
                    lb = mid;
                } else {
                    ub = mid;
                }
            }
            choco[ub]++;
        }

        for (int i = 1; i <= M; i++) {
            choco[i] += choco[i-1];
        }
        int res = INF;
        for (int i = 0; i <= M; i++) {
            int lb = i, ub = M+1;
            int ns = s[i];
            while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                if (ns + (s[M] - s[mid]) < S) {
                    ub = mid;
                } else {
                    lb = mid;
                }
            }

            if (ns + (s[M] - s[lb]) >= S) {
                res = min(res, choco[M] - (choco[lb] - choco[i]));
            }
        }
        cout << res << endl;
    }        
    return 0;
}
