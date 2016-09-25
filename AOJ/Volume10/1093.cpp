#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-10
   
struct Point {
    double x, y;
   
    Point(){}
    Point(double x, double y) : x(x), y(y) {}
   
    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
       
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
       
    Point operator * (const double &k) const {
        return Point(x * k, y * k);
    }
       
    Point operator / (const double &k) const {
        return Point(x / k, y / k);
    }
};

Point operator * (const Point &a, const Point &b)
{
    return Point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
   
double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}
   
double norm(const Point &p)
{
    return dot(p, p);
}
   
double abs(const Point &p)
{
    return sqrt(norm(p));
}
   
double dist(const Point &a, const Point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

struct Circle {
    Point p;
    double r;
    Circle(){}
    Circle(Point p, double r) : p(p), r(r) {}
};
   
bool isIntersectCC(const Circle &a, const Circle &b)
{
    double d = abs(a.p - b.p);
    return (d <= a.r + b.r && d >= abs(a.r - b.r));
}
   
vector<Point> crosspointCC(const Circle &a, const Circle &b)
{
    vector<Point> res;
    double d = abs(a.p - b.p);
    if (!isIntersectCC(a, b) || d < EPS) {
        return res;
    }
    double rc = (a.r * a.r - b.r * b.r + d * d) / (2.0 * d);
    if (abs(a.r) - abs(rc) < EPS) {
        return res;
    }
       
    double rs = sqrt(a.r * a.r - rc * rc);
    Point p = (b.p - a.p);
    res.push_back(Point(a.p + p * Point(rc, +rs) / d));
    res.push_back(Point(a.p + p * Point(rc, -rs) / d));
    return res;
}

bool c(double X,
       vector<double> &x,
       vector<double> &y,
       vector<double> &v)
{
    int N = x.size();
    vector<Circle> c(N);
    for (int i = 0; i < N; i++) {
        double r = v[i] * X;
        c[i].p.x = x[i];
        c[i].p.y = y[i];
        c[i].r = r;
    }

    vector<Point> cross_point;
    for (int i = 0; i < N; i++) {
        cross_point.push_back(c[i].p);
        for (int j = i+1; j < N; j++) {            
            vector<Point> cp = crosspointCC(c[i], c[j]);
            for (int k = 0; k < (int)cp.size(); k++) {
                cross_point.push_back(cp[k]);
            }
        }
    }
       
    for (int i = 0; i < (int)cross_point.size(); i++) {
        bool poss = 1;
        for (int j = 0; j < N; j++) {
            if (dist(cross_point[i], c[j].p) - c[j].r > EPS) {
                poss = 0;
                break;
            }
        }
        if (poss) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int N;
    while (cin >> N, N) {
        vector<double> x(N), y(N), v(N);
        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i] >> v[i];
        }

        double lb = 0, ub = 1LL<<60;
        for (int i = 0; i < 150; i++) {
            double mid = (lb + ub) / 2;
            if (c(mid, x, y, v)) {
                ub = mid;
            } else {
                lb = mid;
            }
        }
        printf("%.10f\n", lb);
    }
    return 0;
}
