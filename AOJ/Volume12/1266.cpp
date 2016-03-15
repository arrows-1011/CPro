#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define EPS (1e-8)

struct Point {
    double x, y, z;
    Point(){}
    Point(double x, double y, double z) :
        x(x), y(y), z(z) {}
};

double dot(const Point &a, const Point &b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

double norm(const Point &p)
{
    return dot(p, p);
}

double abs(const Point &p)
{
    return sqrt(norm(p));
}

bool can_watch(const Point &a, const Point &b, double the)
{
    double t = acos(dot(a, b) / abs(a) / abs(b));
    return (t < the + EPS);
}

int main()
{
    int n, m;
    while (cin >> n, n) {
        vector<Point> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i].x >> s[i].y >> s[i].z;
        }
        Point p;
        double the;
        set<int> stars;
        cin >> m;       
        for (int i = 0; i < m; i++) {
            cin >> p.x >> p.y >> p.z >> the;
            for (int j = 0; j < n; j++) {
                if (can_watch(s[j], p, the)) {
                    stars.insert(j);
                }
            }
        }
        cout << stars.size() << endl;
    }
    return 0;
}
